#include<cstdio>
#include<iostream>

using namespace std;

int n,dp[255][255],cnt[255];
char G[255][255];

int min3(int a,int b,int c)
{
	return min(min(a,b),c);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>G[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(G[i][j]=='1')
				dp[i][j]=min3(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cnt[dp[i][j]]++;
	for(int i=2;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cnt[i]+=cnt[j];
	for(int i=2;i<=n;i++)
		if(cnt[i])
			printf("%d %d\n",i,cnt[i]);
	return 0;
}
