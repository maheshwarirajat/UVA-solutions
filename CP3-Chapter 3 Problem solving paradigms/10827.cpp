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

const long long MOD = 1000000007;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODR(d) ((d)>=MOD?(d)%MOD:(d))
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;

#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++) 
#define MAX 1000000
#define ll long long

using namespace std;

int t,arr[200][200];


int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	
	cin>>t;
	
	
	while(t--)
	{
		int n;
		cin>>n;
		
		//input
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];	
		}
		
		//copy the array--append it
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			arr[i+n][j]=arr[i][j];
			arr[i][j+n]=arr[i][j];
			arr[i+n][j+n]=arr[i][j];
			
		}
		
		//dp sum
		for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
		{
			arr[i][j]+=arr[i][j-1];
			arr[i][j]+=arr[i-1][j];
			arr[i][j]-=arr[i-1][j-1];
		}
		
		
		int ans=INT_MIN;
		
		//calculate maximum
		for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++)
		{
			for(int i1=i;i1<=min(2*n,i+n-1);i1++)
			for(int j1=j;j1<=min(2*n,j+n-1);j1++)
			{
	
				ans=max(ans,arr[i1][j1]-arr[i-1][j1] - arr[i1][j-1] + arr[i-1][j-1]);
				
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
