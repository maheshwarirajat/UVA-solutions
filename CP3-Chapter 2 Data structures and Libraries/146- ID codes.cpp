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
		string s;
		cin>>s;
		
		if(s=="#")
		break;
		
		if(next_permutation(s.begin(),s.end()))
		{
			cout<<s<<endl;
		}
		else
		{
			cout<<"No Successor"<<endl;
		}
	}
	
	return 0;
}
