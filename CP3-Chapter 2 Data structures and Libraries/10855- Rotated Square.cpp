/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE
#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++) 
#define MAX 1000000

using namespace std;

char arrN[110][110],arrn[110][110];

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int N,n;
	
	while(1)
	{
		int ans[4];
		for(int i=0;i<4;i++)ans[i]=0;
		cin>>N>>n;
		if(N==0 && n==0)
		return 0;
		
		cin.ignore();
		for(int i=0;i<N;i++)
		{
		for(int j=0;j<N;j++)
		{
			char c;
			c=getchar();
			arrN[i][j]=c;
		}
		cin.ignore();
		}
		
		for(int i=0;i<n;i++)
		{for(int j=0;j<n;j++)
		{
			char c;
			c=getchar();
			arrn[i][j]=c;
		}
		cin.ignore();
		}
		
		
		for(int rot=0;rot<4;rot++)
		{
			
			for(int i=0;i<N-n+1;i++)
			for(int j=0;j<N-n+1;j++)
			{
				int flag=true;
				
				for(int ii=i,is=0;is<n;ii++,is++)
				for(int jj=j,js=0;js<n;jj++,js++)
				{
					if(arrn[is][js]!=arrN[ii][jj])
					flag=false;
				}
				if(flag)ans[rot]++;
			}
			
			//rotate
			for(int cyc=0;cyc<n/2;cyc++)
			{
				for(int ele=cyc;ele<n-cyc-1;ele++)
				{
					
					int temp=arrn[cyc][ele];
					
					arrn[cyc][ele]=arrn[n-1-ele][cyc];
					arrn[n-1-ele][cyc]=arrn[n-1-cyc][n-1-ele];
					arrn[n-1-cyc][n-1-ele]=arrn[ele][n-1-cyc];
					arrn[ele][n-1-cyc]=temp;
				}
			}
	
		}		
		for(int i=0;i<3;i++)
		cout<<ans[i]<<" ";
		cout<<ans[3]<<endl;
	}
		
	return 0;
}
