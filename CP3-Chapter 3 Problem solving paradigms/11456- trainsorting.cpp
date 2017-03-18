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
#define foreachb(it,c) for(__typeof((c).rbegin()) it = (c).rbegin(); it!=(c).rend(); it++) 
#define MAX 1000000
#define ll long long

using namespace std;

int arr[MAX+5],LIS[MAX+5],LDS[MAX+5];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++)
		cin>>arr[i];
		LIS[0]=1;
		LDS[0]=1;
		
		for(int i=n-1;i>=0;i--)
		{LIS[i]=1;
		for(int j=i+1;j<n;j++)
		{
			
			if(arr[j]<arr[i])
			{
				LIS[i]=max(LIS[i],LIS[j]+1);
			}
			//cout<<LIS[i]<<endl;
		}	}
		
		
		for(int i=n-1;i>=0;i--){
			LDS[i]=1;
		for(int j=i+1;j<n;j++)
		{	
			
			if( arr[i] < arr[j] )
			{
				LDS[i]=max(LDS[i],LDS[j]+1);
			}
			//cout<<LDS[i]<<endl;
		}}
		
		int ans=0;
		for(int i=0;i<n;i++)
		ans=max(LIS[i]+LDS[i]-1,ans);
		
		cout<<ans<<endl;
	}
	
	

	return 0;
}
