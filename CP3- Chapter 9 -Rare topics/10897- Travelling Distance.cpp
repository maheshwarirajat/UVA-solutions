/*    tommy_trash    */
#include<bits/stdc++.h>

#define ll long long
#define PI acos(-1)
#define EPS 1e-9
#define GEOMETRY


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

    bool operator == (point other) const
    {   if (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS)
                return true;
                return false;
    }


	point operator + (const point &p) const
	{
		return point(x + p.x, y + p.y);
	}
	point operator - (const point &p) const
	{
		return point(x - p.x, y - p.y);
	}

};

double dist(point p1, point p2) {return hypot(p1.x - p2.x, p1.y- p2.y);}

point rotate_theta(point p, double theta)
{
    double rad =(theta*PI)/180;
    return point (p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

double gcDistance(double pLat, double pLong,
double qLat, double qLong, double radius) {
pLat *= PI / 180; pLong *= PI / 180;     // convert degree to radian
qLat *= PI / 180; qLong *= PI / 180;
return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
sin(pLat)*sin(qLat)); }



/////////////////////           SOLUTION STARTS HERE          ////////////////////////////////////////////
/////////////////////           SOLUTION STARTS HERE          ////////////////////////////////////////////

int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin>>t;

    while(t--)
    {
        double a,b,c,d,e,f;
        string x,y;
        scanf("%lf%lf%lf",&a,&b,&c);
        cin>>x;
        scanf("%lf%lf%lf",&d,&e,&f);
        cin>>y;
        double lat1= (a+b/60 +c/3600);
        double lon1= (d+ e/60+ f/3600);
        if(x=="S") lat1*=-1;
        if(y=="W") lon1*=-1;
        scanf("%lf%lf%lf",&a,&b,&c);
        cin>>x;
        scanf("%lf%lf%lf",&d,&e,&f);
        cin>>y;
        double lat2= (a+b/60 +c/3600);
        double lon2= (d+ e/60+ f/3600);
        if(x=="S") lat2*=-1;
        if(y=="W") lon2*=-1;

        double ans=gcDistance(lat1,lon1,lat2,lon2,6371.01);
        printf("%.2f\n",ans);

    }
    return 0;
}
