#include<iostream>

using namespace std;

int n,m,ans,sum;

int main()
{
	cin>>n>>m;
	while(n--)
	{
		int x;
		cin>>x;
		if(x+sum<=m)
			sum+=x;
		else
		{
			ans++;
			sum=x;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
