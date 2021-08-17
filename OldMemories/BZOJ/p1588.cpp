#include<set>
#include<iostream>
#include<algorithm>

#define INF (1LL<<32)

using namespace std;

long long ans;

set<long long> S;
set<long long>::iterator s1;

int main()
{
	int n;
	cin>>n;
	if (n==0)
	{
		cout<<"0\n";
		return 0;
	}
	n--;
	int p;
	cin>>p;
	S.insert(p);
	ans=p;
	while(n--)
	{
		int p=0;
		cin>>p;
		s1=S.lower_bound(p);	
		long long t=INF;
		if (s1!=S.end())
			t=min(t,abs((*s1)-p) );
		if (s1!=S.begin())	
			t=min(t,abs((*--s1)-p));
		ans+=t;
		S.insert(p);
	}
	cout<<ans<<endl;
	return 0;
}
