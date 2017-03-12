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

int arr[100000],L[100000],Pred[100000],L_id[100000];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int a,n=0,lis=0,lis_end=0;
	
	while(cint(a)!=EOF)
	{
		arr[n++]=a;
	}
	
	for(int i=0;i<n;i++)
	{
		int pos=lower_bound(L,L+lis,arr[i])-L;
		L[pos]=arr[i];
		L_id[pos]=i;
		Pred[i]= pos ? L_id[pos-1]:-1;
		
		if(pos +1 >lis)
		{
			lis=pos+1;
			lis_end=i;
		}
	}
	
	stack<int> s;
	int x=lis_end;
	for(;Pred[x]>=0;x=Pred[x]) s.push(arr[x]);
	s.push(arr[x]);
	
	cout<<s.size()<<endl<<"-"<<endl;
	
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	
	return 0;
}
