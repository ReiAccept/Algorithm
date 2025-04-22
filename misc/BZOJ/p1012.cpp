#include<bits/stdc++.h>

using namespace std;

long long m,d,t,maxn;
long long a[200003];

int main()
{
	cin>>m>>d;
	for(long long i=1;i<=m;i++)
	{
		char cz;
		cin>>cz;
		if(cz=='Q')
		{
			long long l,maxx=0;
			cin>>l;
			for(long long j=maxn-l+1;j<=maxn;j++)
				if(a[j]>maxx)
					maxx=a[j];
			t=maxx;
			cout<<maxx<<endl;
		}
		if(cz=='A')
		{
			long long n;
			cin>>n;
			n+=t;
			n%=d;
			a[++maxn]=n;
		}
	}
	return 0;
}
