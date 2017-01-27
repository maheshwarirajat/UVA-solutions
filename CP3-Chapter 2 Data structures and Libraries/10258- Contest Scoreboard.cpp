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

int prob[110];
int arr_time[110];
int arr_prob[110][10][2];



bool compare (const int first,const int second)
{
	if(prob[first]>prob[second]) return 1;
	else if(prob[first]==prob[second])
	{
		if(arr_time[first] < arr_time[second])return 1;
		else if(arr_time[first]==arr_time[second])return (first<second);
		else return 0;
	}
	else return 0;
}

vector<int> v;
int cont[110];


int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;
	cin>>t;
	cin.ignore();
	
	while(t--)
	{
		v.clear();
		for(int i=0;i<110;i++) {arr_time[i]=0;prob[i]=0;cont[i]=0;}
		for(int i=0;i<110;i++) 
		for(int j=0;j<10;j++) {arr_prob[i][j][0]=0; arr_prob[i][j][1]=0;}
				
		int c_no,p_no,time;
		char l;
		
		while(1)
		{
			cin.ignore();
			
			if(cin.peek()!='\n' && cin.peek()!=-1)
			cint4(c_no,p_no,time,l);
			else break;
			
			if(cont[c_no]==0) {v.push_back(c_no);cont[c_no]=1;}

				if(l=='C' && arr_prob[c_no][p_no][0]==0)
				{
					prob[c_no]++;
					arr_time[c_no]+=(time + arr_prob[c_no][p_no][1]*20);
					arr_prob[c_no][p_no][0]=1;
				}
				else if(l=='I' && arr_prob[c_no][p_no][0]==0)
				{
					arr_prob[c_no][p_no][1]++;
				}
		}
		
		sort(v.begin(),v.end(),compare);
		
		foreach(it,v)
		{
			printf("%d %d %d\n",*it,prob[*it],arr_time[*it]);
		}
		if(t)
		cout<<endl;
	}
	
	return 0;
}
