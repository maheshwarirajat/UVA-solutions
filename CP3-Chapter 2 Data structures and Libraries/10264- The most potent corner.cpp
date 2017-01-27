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

int arr[1<<16];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;
	while(cint(n)!=EOF)
	{
		int out=0;
		for(int i=0;i<(1<<n);i++)
		{
			cin>>arr[i];
		}
		
		for(int j=0;j<(1<<n);j++)
		{
			int sum1=0,out2=0;
			for(int i=0;i<n;i++)
			{
				int sum2=0;
				int neighbour=(j^(1<<i));
				
				for(int k=0;k<n;k++)
				{
					sum2+=arr[neighbour^(1<<k)];
				}
				out2=max(out2,sum2);
				
				sum1+=arr[j^(1<<i)];
			}
			out=max(out,sum1+out2);
		}
		
		cout<<out<<endl;
	}	
	
	return 0;
}
