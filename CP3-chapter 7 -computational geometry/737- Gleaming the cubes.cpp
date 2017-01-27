/*    tommy_trash    */
#include<bits/stdc++.h>

#define repi(a,b,c) for(int i=a;i<b;i+=c)
#define repj(a,b,c) for(int j=a;j<b;j+=c)
#define ll long long
#define PI acos(-1)
#define EPS 1e-9
#define GEOMETRY


using namespace std;

int t;
pair<int,int> rangex,rangey,rangez;

void update(pair<int,int> p, pair<int,int> range)
{

    if(p.first <= range.first && p.second >= range.second ) { return;}

    if(p.first >range.second || p.second < range.first  || range.first>range.second ) { range.first=range.second=0;

    if(t==1){ rangex.first=range.first; rangex.second=range.second; }
    if(t==2){ rangey.first=range.first; rangey.second=range.second; }
    if(t==3){ rangez.first=range.first; rangez.second=range.second; }

    return;

    }

    if(range.first < p.first ) range.first=p.first;

    if(range.second > p.second ) range.second=p.second;

    if(t==1){ rangex.first=range.first; rangex.second=range.second; }
    if(t==2){ rangey.first=range.first; rangey.second=range.second; }
    if(t==3){ rangez.first=range.first; rangez.second=range.second; }

    return;


}


int main()
{
    #ifdef GEOMETRY_
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	while(1)
    {
       int n;
       cin>>n;
       if(n==0) return 0;
       rangex.second=INT_MAX,rangex.first=INT_MIN;
       rangey.second=INT_MAX,rangey.first=INT_MIN;
       rangez.second=INT_MAX,rangez.first=INT_MIN;

       for(int i=0;i<n;i++)
       {
           int x,y,z,a;
           cin>>x>>y>>z>>a;

           t=1;
           update(make_pair(x,x+a), rangex);
           t=2;
           update(make_pair(y,y+a), rangey);
           t=3;
           update(make_pair(z,z+a), rangez);

       }

       cout<<(rangex.second - rangex.first)*(rangey.second - rangey.first)*(rangez.second - rangez.first)<<endl;

    }

    return 0;

}
