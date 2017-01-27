/*    tommy_trash    */
#include<bits/stdc++.h>

#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
#define ll long long
#define PI acos(-1)
#define EPS 1e-9
#define GEOMETRY


using namespace std;

int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    int n;
    cin>>n;

    while(n--)
    {
        double l,d;
        cin>>d>>l;

        //ellipse
        double a=l/2;
        double b=sqrt(l*l - d*d)/2;

        printf("%.3f\n",PI*a*b);

    }

    return 0;

}
