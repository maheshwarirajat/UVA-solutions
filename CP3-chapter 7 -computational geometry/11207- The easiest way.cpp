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
    #ifdef GEOMETRY
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	while(1)
    {
       double l,c,r1,r2;
       cin>>l>>c>>r1>>r2;

       if(l==0 && c==0 && r1==0 && r2==0) return 0;

       double mn=min(l,c);
       double mx=max(l,c);

       double R1=max(r1,r2);
       double R2=min(r1,r2);

       double y= mx-R1-R2;
       double x= mn- R1 -R2;

       if(x*x +y*y >= (R1+R2)*(R1+R2)  && y>0 && x>0 )
        cout<<"S"<<endl;
       else cout<<"N"<<endl;
    }

    return 0;

}
