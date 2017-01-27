/*    tommy_trash    */
#include<bits/stdc++.h>

#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
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

point rotate_theta(point p, double rad)
{
   // double rad =(theta*PI)/180;
    return point (p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}


//////////////////////                VECTORS              ///////////////////////
struct vec
{
    double x,y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

int ccw (point p, point q, point r)
{
    double t=cross(toVec(p,q), toVec(p,r) );
    if(t>0) return true;
    else return false;
}

bool collinear( point p, point q, point r) { return fabs(cross(toVec(p,q), toVec(p,r))) < EPS; }

point pivot(0,0);
bool angleCmp(point a, point b)
{
    if(collinear(pivot,a,b)) return dist(pivot,a) < dist(pivot,b);
    double d1x= a.x-pivot.x, d2x= b.x-pivot.x;
    double d1y= a.y-pivot.y, d2y= b.y-pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P)
{
    //pivot -figure out
    int i,j,n=(int)P.size();

    if(n<=3)
    {
        if(!(P[0]==P[n-1]))P.push_back(P[0]);
        return P;
    }

    int P0=0;
    for( i=1;i<n ;i++)
    {
        if(P[i].y < P[P0].y  || ( P[i].y==P[P0].y && P[i].x < P[P0].x ) ) P0=i;
    }

    point temp = P[0]; P[0]=P[P0]; P[P0]=temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);

    vector<point> S;
    S.push_back(P[n-1]);S.push_back(P[0]);S.push_back(P[1]);
    i=2;
    while (i<n)
    {
        j=(int)S.size()-1;
        if(ccw(S[j-1], S[j], P[i]))
            S.push_back(P[i++]);
        else
        S.pop_back();
    }
    return S;
}



int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    int t=1;
    while(t)
    {
        int n;
        double ans=DBL_MAX;
        cin>>n;
        if(n==0) return 0;

        vector<point> v;
        point p;
        for(int i=0;i<n;i++)
        {
            cin>>p.x>>p.y;
            v.push_back(p);
        }
        v=CH(v);
        n=v.size();

        for(int i=0;i<n;i++)
        {
            set<point> s;
            s.clear();
            double dx=v[i+1].x - v[i].x, dy=v[i+1].y - v[i].y;
            double slope=atan2(dy, dx);

            slope=(PI/2)-slope;
            for(int j=0;j<n;j++)
            {
                s.insert(rotate_theta(v[j],slope));
            }

            if(ans > (s.rbegin()->x) - s.begin()->x )
                ans=(s.rbegin()->x) - s.begin()->x;
        }

        printf("Case %d: %.2f\n",t++,ans);
    }

    return 0;

}
