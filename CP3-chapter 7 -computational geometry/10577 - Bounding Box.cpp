/*    tommy_trash    */
#include<bits/stdc++.h>

#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
#define ll long long
#define PI acos(-1)
#define EPS 1e-9


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


/////////////////////////////            LINES         ///////////////////////////////

struct line { double a, b, c; };
struct line_m{ double m,c; };

void pointsToLine(point p1, point p2, line &l )
{
    if (fabs(p1.x -p2.x) < EPS) { l.a = 1.0; l.b = 0.0; l.c = -p1.x;}
    else
    {
        l.a = -(double)(p1.y - p2.y)/ (p1.x -p2.x);
        l.b= 1.0;
        l.c = -(double)(l.a *p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) { return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areIntersect( line l1, line l2, point &p)
{
    if(areParallel(l1,l2)) return false;
    p.x= (l2.b * l1.c -l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS) p.y= -(l1.a * p.x + l1.c);
    else                     p.y= -(l2.a * p.x + l2.c);
    return true;
}


double heron( double ab, double bc, double ca)
{
    double s= (ab+bc+ca)/2;
    return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}


double rCircumCircle(double ab, double bc, double ca) { return ab* bc * ca / (4.0 * heron(ab, bc, ca)); }
double rCircumCircle( point a, point b, point c) { return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }


int circumCircle(point p1, point p2, point p3, point &ctr, double &r )
{
    r = rCircumCircle(p1,p2,p3);
    if(fabs(r) < EPS) return 0;

    line l1,l2;
    point mid;
    mid.x=(p1.x+p2.x)/2; mid.y = (p1.y + p2.y)/2;
    p2.x-=mid.x; p2.y-=mid.y;
    double temp;
    temp=p2.x;
    p2.x=-p2.y; p2.y=temp;
    p2.x+=mid.x; p2.y+=mid.y;
    pointsToLine(mid, p2, l1);

    mid.x=(p1.x+p3.x)/2; mid.y = (p1.y + p3.y)/2;
    p3.x-=mid.x; p3.y-=mid.y;
    temp=p3.x;
    p3.x=-p3.y; p3.y=temp;
    p3.x+=mid.x; p3.y+=mid.y;
    pointsToLine(mid, p3, l2);

    areIntersect(l1, l2, ctr);
    return 1;
}




/////////////////////            CODE STARTS FROM HERE              /////////////////////////////


int main()
{
    #ifdef GEOMETRY
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


    int t;
    t=1;
    while(t++)
    {
        //input
            set<point> s;
            double n;
            cin>>n;
            if(n==0) return 0;
            point a,b,c,ctr;
            double r;
            cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
            s.insert(a);


        //circumcircle
            if(circumCircle(a,b,c,ctr,r))
            {
                    double rotating_angle=360.0/n;

                     n--;
                    while(n--)
                    {
                            a.x-=ctr.x;
                            a.y-=ctr.y;

                           a=rotate_theta(a,rotating_angle);

                           a.x+=ctr.x;
                           a.y+=ctr.y;

                           s.insert(a);
                    }

            }

            double ymin=DBL_MAX,xmin=DBL_MAX,xmax=-DBL_MAX,ymax=-DBL_MAX;

            for(set<point> ::iterator it=s.begin(); it!=s.end(); it++)
            {
                    if( it->x<xmin) xmin=it->x;
                    if(it->y<ymin) ymin=it->y;
                    if(it->x>xmax) xmax=it->x;
                    if(it->y>ymax) ymax=it->y;
            }

            printf("Polygon %d: ",t-1);
            printf("%.3f\n", (xmax-xmin)*(ymax-ymin) );

    }

    return 0;

}
