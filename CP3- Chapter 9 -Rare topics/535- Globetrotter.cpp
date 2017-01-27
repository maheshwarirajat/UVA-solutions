/*    tommy_trash    */
#include<bits/stdc++.h>

#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
#define ll long long
#define PI 3.141592653589793
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

#define R 6378.0
double spherical_distance(double lat1,double lon1,double lat2,double lon2) {

       lat1 *= PI / 180; lon1 *= PI / 180;     // convert degree to radian
        lat2*= PI / 180; lon2 *= PI / 180;
       double dlon = lon2 - lon1;
       double dlat = lat2 - lat1;
       double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
       double c = 2 * atan2(sqrt(a), sqrt(1-a));
       double d = R * c;
       return d;
}

double gcDistance(double pLat, double pLong,
double qLat, double qLong, double radius) {
pLat *= PI / 180; pLong *= PI / 180;     // convert degree to radian
qLat *= PI / 180; qLong *= PI / 180;
return radius * acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) + cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) + sin(pLat)*sin(qLat)); }


/////////////////////           SOLUTION STARTS HERE          ////////////////////////////////////////////
/////////////////////           SOLUTION STARTS HERE          ////////////////////////////////////////////

map<string, pair<double,double> > m;

int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


    string s;

    while(1)
    {
        cin>>s;
        if(s=="#") break;

        double lat,lon;
        cin>>lat>>lon;
        m[s]=make_pair(lat,lon);
    }

    string s_;
    while(1)
    {
        cin>>s;
        cin>>s_;
        if(s=="#" || s_=="#") break;
        cout<<s<<" - "<<s_<<endl;

        if(m.find(s)==m.end() || m.find(s_)==m.end())
        {
            cout<<"Unknown"<<endl;
            continue;
        }


        double ans=spherical_distance(m[s].first, m[s].second, m[s_].first, m[s_].second);

       ans=ans+0.5;
        cout<<(long long)ans<<" km"<<endl;

    }

    return 0;
}
