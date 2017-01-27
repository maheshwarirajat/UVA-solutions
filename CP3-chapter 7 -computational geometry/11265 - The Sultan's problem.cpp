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
bool areSame(line l1, line l2) { return areParallel( l1, l2) && (fabs(l1.c - l2.c) < EPS); }

bool areIntersect( line l1, line l2, point &p)
{
    if(areParallel(l1,l2)) return false;
    p.x= (l2.b * l1.c -l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS) p.y= -(l1.a * p.x + l1.c);
    else                     p.y= -(l2.a * p.x + l2.c);
    return true;
}



//////////////////////                VECTORS              ///////////////////////
struct vec
{
    double x,y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }

vec scale ( vec v, double s ) { return vec(v.x * s, v.y * s); }

point translate (point p, vec v) { return point(p.x +v.x, p.y+v.y); }

double dot(vec a, vec b) { return (a.x *b.x + a.y*b.y); }

double norm_sq(vec v) { return v.x*v.x + v.y*v.y ;}

double distToLine( point p,point a, point b, point &c)
{
    vec ap=toVec(a,p), ab=toVec(a,b);
    double u= dot(ap, ab)/ norm_sq(ab);
    c= translate(a,scale(ab,u));

    return dist(p,c);
}

double distToLineSegment (point p, point a, point b, point &c)
{
    vec ap=toVec(a,p), ab=toVec(a,b);
    double u=dot(ap,ab)/norm_sq(ab);

    if(u<0.0)
    {
        c=point(a.x,a.y);
        return dist(p,a);
    }

    if(u>1.0)
    {
        c=point(b.x,b.y);
        return dist(p,b);
    }

    return distToLine(p,a,b,c);
}

//remember about order of points
double angle (point a, point o, point b)
{
    vec oa=toVec(o,a), ob=toVec(o,b);
    return acos(dot(oa,ob)/ sqrt(norm_sq(oa)* norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

int ccw (point p, point q, point r)
{
    double t=cross(toVec(p,q), toVec(p,r) );
    if(t>0) return true;
    else return false;
}

bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

bool collinear( point p, point q, point r) { return fabs(cross(toVec(p,q), toVec(p,r))) < EPS; }

///////////////////////////          POLYGONS               //////////////////////////////

double area(const vector<point> &P)
{
    double result =0.0, x1,y1,x2,y2;
    for(int i=0; i< (int)P.size()-1; i++)
    {
        x1=P[i].x; x2=P[i+1].x;
        y1=P[i].y; y2=P[i+1].y;
        result+= (x1*y2 - x2*y1);
    }

    return fabs(result)/2.0;
}

bool inPolygon( point pt, const vector<point> &P )
{
    if((int)P.size()==0) return false;
    double sum=0;
    for(int i=0; i< (int)P.size()-1; i++)
    {
        if(ccw(pt, P[i], P[i+1]))
            sum+= angle(P[i], pt, P[i+1]);
        else sum-= angle(P[i], pt, P[i+1]);
    }

    return fabs(fabs(sum)- 2*PI) < EPS;
}

point lineIntersectSeg(point p, point q, point A, point B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c =  B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point( (p.x * v + q.x *u) / (u+v), (p.y * v + q.y * u) / (u+v) );
}

vector<point> cutPolygon(point a, point b, const vector<point> &Q)
{
    vector<point> P;
    for(unsigned int i=0; i<Q.size(); i++)
    {
        double left1= cross(toVec(a,b), toVec(a,Q[i])), left2=0;
        if(i!= Q.size()-1) left2 =cross(toVec(a,b), toVec(a,Q[i+1]));
        if(left1 >-EPS ) P.push_back(Q[i]);
        if(left1 * left2 < -EPS) P.push_back(lineIntersectSeg(Q[i],Q[i+1],a,b));

    }

    if(!P.empty() && !(P.front()==P.back())) P.push_back(P.front());
    return P;
}

////////////////////////////////////// SOLUTION STARTS FROM HERE////////////////////////////////////

vector<point> v;

int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t=1;
        point p;
        int n,w,h;


	while (scanf("%d %d %d %lf %lf", &n, &w, &h, &p.x, &p.y) !=EOF)
    {

        //initial polygon
        vector<point> v;
        v.push_back(point(0,0));
        v.push_back(point(w,0));
        v.push_back(point(w,h));
        v.push_back(point(0,h));
        v.push_back(v[0]);

        for(int i=1;i<=n;i++)
        {
            point p1,p2;
            cin>>p1.x>>p1.y>>p2.x>>p2.y;

            vector<point> left;
            vector<point> right;
            left=cutPolygon(p1,p2,v);
            right=cutPolygon(p2,p1,v);

            if( inPolygon(p,left) )
            {
                v=left;
            }

            else

            {
                v=right;
            }

        }

        printf("Case #%d: ",t++);
        printf("%.3f\n",area(v));
    }

    return 0;

}
