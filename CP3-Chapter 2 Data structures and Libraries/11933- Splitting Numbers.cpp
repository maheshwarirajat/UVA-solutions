/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE

#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %c", &a, &b, &c, &d)

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
	
	int n;
	
	while(1)
	{
		cin>>n;
		if(n==0) break;
		int a=n,b=n;
		bool first=1,second=0;
		
		for(int i=0;i<32;i++)
		{
			if(first)
			if(n & (1<<i))
			{
				b= b^(1<<i);
			}
			
			if(second)
			 if(n & (1<<i))
			{
				a=a^(1<<i);
			}
			
			if(n & (1<<i))
			{first^=1;
			second^=1;}
		}
		
		cout<<a<<" "<<b<<endl;
		
	}
	
	
	return 0;
}
