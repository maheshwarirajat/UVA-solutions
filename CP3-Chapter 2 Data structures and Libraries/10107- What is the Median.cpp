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


template<class T> using minimum_heap = priority_queue<T, std::vector<T>, std::greater<T> >;

priority_queue<int> max_heap;
minimum_heap<int> min_heap;

int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	int size=0;
	
	cint(n);
	max_heap.push(n);
	size++;
	
	cout<<n<<endl;
	
	while(cint(n)!=EOF)
	{
		size++;
		
		if(min_heap.size()<max_heap.size())
		{
			if(n>max_heap.top())
			{
				min_heap.push(n);
			}
			else
			{
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(n);
			}
		}
		else
		{
			if(n<=min_heap.top())
			{
				max_heap.push(n);
			}
			
			else
			{
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(n);
			}
		}
		
		
		if(size%2==1)
		{
			cout<<max_heap.top()<<endl;
		}
		else
		{
			cout<<(max_heap.top() + min_heap.top())/2<<endl;
		}
		
	}
	
	
	return 0;
}
