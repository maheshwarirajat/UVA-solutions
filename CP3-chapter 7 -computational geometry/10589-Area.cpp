/*    tommy_trash    */
#include<bits/stdc++.h>

#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
#define ll long long
#define PI acos(-1)
#define EPS 1e-9
#define GEOMETRY
#define chuckie 


using namespace std;

//////////////////////////          POINTS     /////////////////////////////////
struct point_i
{
    int x,y;
    point_i () { x=y=0; }
    point_i (int _x, int _y) : x(_x), y(_y) {}
};

struct point
{
    double x,y;
    point() { x=y=0.0; }
    point (double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const
    {   if (fabs(x - other.x) > EPS)
      return x < other.x;
      return y < other.y; }
};

double dist(point p1, point p2) {return hypot(p1.x - p2.x, p1.y- p2.y);}

point rotate_theta(point p, double theta)
{
    double rad =(theta*PI)/180;
    return point (p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}




///////////////////////            CIRCLES             //////////////////////////////////////////
//integer version
struct circle{ point_i c; int r;};

int insideCircle ( point p, point c, double r )
{
    double dx=p.x - c.x, dy = p.y - c.y;
    double Euc = dx*dx + dy*dy, rSq = r*r;
    return Euc <= rSq ? 1 : 0;
}

bool circle2PtsRad(point p1, point p2, double r, point &c)
{
    double d2 = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y) *(p1.y-p2.y);
    double det=r*r / d2 -0.25;

    if(det < 0.0) return false;
    double h=sqrt(det);
    c.x=(p1.x +p2.x) * 0.5 + (p1.y - p2.y) *h;
    c.y = (p1.y + p2.y) * 0.5 +(p2.x - p1.x)* h;
    return true;
}


int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    while(1)
    {
        int n,m=0;
        double a;
        point p;
        cin>>n>>a;

        if(n==0 && a==0) return 0;

        for(int i=0;i<n;i++)
        {
            cin>>p.x>>p.y;
            int t=insideCircle(p,point(0,0),a) +insideCircle(p,point(a,0),a) +insideCircle(p,point(0,a),a) +insideCircle(p,point(a,a),a);

            if(t==4) m++;
        }

        printf("%.5f\n",m*a*a/n);
    }

    return 0;

}
