#include<cmath>
#include<cstdio>
#include<iostream>

using namespace std;

int Case,n;
long long ans;
long long a[1000003],b[1000003];

int main()
{
	ios::sync_with_stdio(false);
	cin>>Case;
	while(Case--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				ans+=sqrt(abs(a[i]-b[j]));
			}
		cout<<ans<<endl;
	}
	return 0;
}
