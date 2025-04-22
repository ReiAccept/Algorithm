#include<iostream>

using namespace std;

int n,m,ans;
long long k;
long long a[23][23];

void dfs(int i,int j,long long sum)
{
	if(j+1<=m)
		dfs(i,j+1,sum^a[i][j+1]);
	if(i+1<=n)
		dfs(i+1,j,sum^a[i+1][j]);
	if(sum==k && i==n && j==m)
	{
		ans++;
		return;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	dfs(1,1,a[1][1]);
	cout<<ans<<endl;
	return 0;
}
