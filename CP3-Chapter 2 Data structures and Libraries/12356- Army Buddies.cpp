/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE
#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define MAX 100000

using namespace std;


struct data
{
	int left;
	int right;
};

data arr[MAX+5];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	while(1)
	
	{
		int b,s;
		cin>>s>>b;
		
		if(b==0 && s==0) break;
		
		for(int i=1;i<=s;i++) 
		{
			arr[i].left=i-1;
			arr[i].right=i+1;	
		}
		arr[s].right=0;
		
		for(int i=0;i<b;i++)
		{
			int l,r;
			cin>>l>>r;
			
			if(arr[l].left)
			{
				cout<<arr[l].left<<" ";
			}
			else cout<<"* ";
			
			if(arr[r].right)
			{
				cout<<arr[r].right;
			}
			else cout<<"*";
			
			arr[arr[l].left].right=arr[r].right;
			arr[arr[r].right].left=arr[l].left;
			
			cout<<endl;
			
		}
		cout<<'-'<<endl;
		
	}
	


	return 0;
}
