/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE
#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++) 
#define MAX 10000000

using namespace std;



int arr[MAX];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;
	
	while(scanf("%d", &n) != EOF){
		
	for(int i=0;i<=n;i++) arr[i]=0;
		
	int prev,curr,flag=0;
	cin>>prev;
	
		for(int i=1;i<n;i++)
		{
				cin>>curr;
				arr[abs(curr-prev)]=1;
				prev=curr;
		}
		
		for(int i=1;i<n;i++)
		{
			if(arr[i]!=1) {flag=1;break;}
		}
		
		if(flag==1) cout<<"Not jolly"<<endl;
		else cout<<"Jolly"<<endl;
	
	}
	return 0;
}

