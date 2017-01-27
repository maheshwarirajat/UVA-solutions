/*    tommy_trash    */
#include <stdio.h>
#include <math.h>
#include <map>
#include <iostream>
#include <algorithm>
#define PI acos(-1)
#define EPS 1e-6
#define GEOMETRY


using namespace std;


int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    int n;
    double vlat[1005],vlon[1005],w[1005],t, cosll[1005],csll[1005] ;
    while(scanf("%d",&n)==1)

    {
       for(int i=0;i<n;i++)
       {
           scanf("%lf%lf",&vlat[i],&vlon[i]);
           w[i]=vlat[i]*PI/180;
           t=vlon[i]*PI/180;
           cosll[i]=cos(w[i]) * cos(t);
           csll[i]= cos(w[i]) * sin(t);
       }

       double ans=1e+30,lat=vlat[0],lon=vlon[0];

       for(int i=0;i<n;i++)
       {
           double dis=0;
           for(int j=0;j<n ;j++)
           {
               if(i==j)continue;


                double c=acos(cosll[i]*cosll[j] + csll[i]*csll[j] + sin(w[i])*sin(w[j]) );
                dis=max(dis,6378*c);
                    if(dis>ans+EPS) break;
           }
           if(ans>=(dis -EPS) )
           {
               ans=dis;
               lat=vlat[i];
               lon=vlon[i];
           }
       }

       printf("%.2f %.2f\n",lat,lon);
    }


    return 0;
}
