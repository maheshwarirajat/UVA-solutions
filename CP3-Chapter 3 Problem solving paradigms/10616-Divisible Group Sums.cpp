/*  chuckie   */
#include <bits/stdc++.h>
#define CHUCKIE

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
#define foreachb(it,c) for(__typeof((c).rbegin()) it = (c).rbegin(); it!=(c).rend(); it++) 
#define MAX 200
#define ll long long

ll negmod(ll number, ll mod)
{
    if(number >= 0) return number % mod;
    return (mod + (number % mod)) % mod;
}

using namespace std;

ll d,m,n,q,arr[MAX+5],ans=0,memo[250][25][25];

ll val(ll idx, ll length, ll sum)
{
	if(length==0 && sum==0) return 1;
	if(idx==n || length==0) return 0;
	
	if(memo[idx][length][sum]!=-1) return memo[idx][length][sum];
	else return memo[idx][length][sum]=(val(idx+1,length,sum)+val(idx+1,length-1,negmod(sum+arr[idx],d)));
	
}


int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=0;
	while(1)
	{
		cin>>n>>q;
		
		if(n==0 && q==0)return 0;
		
		for(int i=0;i<n;i++) cin>>arr[i];
		
		cout<<"SET "<<++t<<":"<<"\n";
		for(int i=0;i<q;i++)
		{
			
			memset(memo,-1,sizeof(memo));
			cin>>d>>m;
			ans=val(0,m,0);

			cout<<"QUERY "<<i+1<<": "<<ans<<"\n";
		}
		
	}

	return 0;
}
