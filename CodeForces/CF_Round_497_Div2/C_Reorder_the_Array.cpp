#include<iostream>
#include<algorithm>

using namespace std;

int n,ans,tmp;
int a[100003];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			tmp++;
		}
		else
		{
			ans=max(ans,tmp);
			tmp=1;
		}
	}
	cout<<n-ans<<endl;
	return 0;
}
