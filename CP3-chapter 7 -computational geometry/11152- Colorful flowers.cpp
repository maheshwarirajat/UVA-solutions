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
    if(t==0) return 0;

    if(t>0) return 1;
    else return 2;
}

bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

bool collinear( point p, point q, point r) { return fabs(cross(toVec(p,q), toVec(p,r))) < EPS; }



///////////////////////            CIRCLES             //////////////////////////////////////////
//integer version
struct circle{ point_i c; int r;};

int insideCircle ( point_i p, point_i c, int r )
{
    int dx=p.x - c.x, dy = p.y - c.y;
    int Euc = dx*dx + dy*dy, rSq = r*r;
    return Euc < rSq ? 0 : Euc == rSq ? 1: 2;
}



//////////////////////                TRIANGLES           ////////////////////////////////////////

double heron( double ab, double bc, double ca)
{
    double s= (ab+bc+ca)/2;
    return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}

double rInCircle(double ab, double bc, double ca) { return heron(ab,bc,ca)/ (0.5 * (ab+bc+ca)); }
double rInCircle(point a, point b, point c) { return rInCircle(dist(a,b),dist(b,c), dist(c,a) ); }

int inCircle ( point p1, point p2, point p3, point &ctr, double &r )
{
    r = rInCircle(p1,p2,p3);
    if (fabs(r) < EPS ) return 0;

    line l1,l2;
    double ratio = dist(p1, p2) / dist(p2,p3);
    point p=translate(p2, scale(toVec(p2,p3), ratio / (1+ratio)));

    ratio = dist(p2,p1) / dist(p2,p3);
    p= translate(p1, scale(toVec(p1,p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);

    areIntersect(l1, l2, ctr);
    return 1;
}

double rCircumCircle(double ab, double bc, double ca) { return ab* bc * ca / (4.0 * heron(ab, bc, ca)); }
double rCircumCircle( point a, point b, point c) { return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

bool check_triangle (double a, double b, double c) { if((a+b > c) && (b+c > a) && (a+c > b) ) return true; else return false; }

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


int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    double a,b,c,a_circle, a_triangle, a_bigcircle;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3){
    a_circle=(double)PI*pow(rInCircle(a,b,c),2);

    a_triangle=heron(a,b,c)-a_circle;

    a_bigcircle= (double)PI*pow(rCircumCircle(a,b,c),2) - a_triangle - a_circle;

    cout << fixed << showpoint;
    cout << setprecision(4);
    cout << a_bigcircle <<" "<< a_triangle<<" " << a_circle<<endl;
    }

    return 0;

}
