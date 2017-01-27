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
	
	int n,m;
	while(1)
	{
		int flag=0;
		bitset<MAX+5> arr;
		cin>>n>>m;
		if(n==0 && m==0) break;
		arr.reset();
		
		int arrn[110][2];
		int arrm[110][3];
		
		for(int i=0;i<n;i++) cin>>arrn[i][0]>>arrn[i][1];
		
		for(int i=0;i<m;i++) cin>>arrm[i][0]>>arrm[i][1]>>arrm[i][2];
		
		
		for(int i=0;i<n;i++)
		{
			for(int j=arrn[i][0];j<arrn[i][1];j++)
			{
				if(arr[j]==0)
				arr[j]=1;
				else
				{
					flag=true;
					break;
				}
			}
			if(flag==true) break;
		}
		
		if(flag==false)
	{
		for(int i=0;i<m;i++)
		{
			int j=arrm[i][0];
			while(j<=1000000)
			{
				int cnt=arrm[i][1]-arrm[i][0];
				for(int k=j;k<j+cnt && k<=1000000;k++)
				{
					if(arr[k]==0) arr[k]=1;
					else 
					{
						flag=true;
						break;
					}
				}
				j+=arrm[i][2];
				
				if(flag)break;
			}
			
			if(flag)break;
		}	
	}
	
	if(flag)cout<<"CONFLICT"<<endl;
	else cout<<"NO CONFLICT"<<endl;
		
	}
	
	return 0;
}
