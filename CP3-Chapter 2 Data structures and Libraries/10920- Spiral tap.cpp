/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE

#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++) 
#define MAX 1000000
#define ll long long

using namespace std;

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	while(1)
	{
		ll s,p;
		clong2(s,p);
		
		if(s==0 && p==0) return 0;
		
		ll n=sqrt(p);
		if(n%2==0)n--;
		
		if(n==sqrt(p))
		{
			printf("Line = %lld, column = %lld.\n",s/2 + 1 + n/2,s/2 + 1 + n/2);
			continue;
		}

		ll pos=n*n,pos2=(n+2)*(n+2) ,x=0,y=0;
		
		if(p<=pos +n+1) 
		{
			x=s/2 + 2 + n/2;
			y= x-(p-(pos+1))-1;
		}
		
		else if(p<=pos + 2*n +2) 
		{
			y=s/2 -n/2;
			x= y + (pos + 2*n + 2 -p); 
		}
		
		else if(p<=pos + 3*n + 3) 
		{
			x=s/2 -n/2;
			y= x + p-(pos + 2*n +2 );
		}
		
		else if(p<=pos2) 
		{
			y=s/2 +2 +n/2;
			x= y - (pos2 - p);
			
		}
		
		
		printf("Line = %lld, column = %lld.\n",x,y);
		
	}
		
	return 0;
}
