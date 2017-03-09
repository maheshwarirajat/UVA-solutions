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

const int MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODR(d) ((d)>=MOD?(d)%MOD:(d))
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;

#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++) 
#define MAX 1000000
#define ll long long

using namespace std;

ll arr[25][25][25];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		
		//input--DP sum
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				for(int k=1;k<=c;k++)
				{
					cin>>arr[i][j][k];
					
					arr[i][j][k]+=arr[i][j][k-1];
					arr[i][j][k]+=arr[i][j-1][k];
					arr[i][j][k]+=arr[i-1][j][k];
					arr[i][j][k]-=arr[i-1][j-1][k];
					arr[i][j][k]-=arr[i-1][j][k-1];
					arr[i][j][k]-=arr[i][j-1][k-1];
					
					arr[i][j][k]+=arr[i-1][j-1][k-1];
				}
				
		
		// count max;
		ll maxcube=INT_MIN;
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				for(int k=1;k<=c;k++)
				{
					for(int i1=1;i1<=i;i1++)
					for(int j1=1;j1<=j;j1++)
					for(int k1=1;k1<=k;k1++)
					{
						
						maxcube=max(maxcube,arr[i][j][k]-arr[i1-1][j][k]-arr[i][j1-1][k]-arr[i][j][k1-1]+arr[i][j1-1][k1-1]+arr[i1-1][j][k1-1]+arr[i1-1][j1-1][k]-arr[i1-1][j1-1][k1-1]);
					}
				}
				
		cout<<maxcube<<endl;
		if(t!=0)cout<<endl;
	}
	
	
	return 0;
}
