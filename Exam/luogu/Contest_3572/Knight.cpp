#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int n,sx,sy;
char G[53][53];
bool dp[53][53];

void init();

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>G[i][j];
			if(G[i][j]=='O')
				sx=i,sy=j;
		}
	init();
	return 0;
}

void init()
{
	bool fuck;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			switch(G[i][j])
			{
				case 'P':dp[i-1][j-1]=dp[i+1][j-1]=true;break;
				case 'X':dp[i-1][j-1]=dp[i][j-1]=dp[i-1][j-1]=dp[i-1][j]=dp[i+1][j]=dp[i-1][j+1]=dp[i][j+1]=dp[i-1][j+1]=true;break;
				case 'Q':fuck=dp[i][j];for(int k=1-min(i,j);i+k<=n&&j+k<=n;k++)dp[i+k][j+k]=true;for(int k=1;k<=n;k++)dp[k][i]=dp[i][k]=true;dp[i][j]=fuck;break;
				case 'B':fuck=dp[i][j];for(int k=1-min(i,j);i+k<=n&&j+k<=n;k++)dp[i+k][j+k]=true;dp[i][j]=fuck;break;
				case 'K':dp[i+1][j+2]=dp[i+2][j+1]=dp[i+1][j-2]=dp[i+2][j-1]=dp[i-1][j+2]=dp[i-2][j+1]=dp[i-1][j-2]=dp[i-2][j-1]=true;break;
				case 'C':fuck=dp[i][j];for(int k=1;k<=n;k++)dp[k][i]=dp[i][k]=true;dp[i][j]=fuck;break;
				default : break;
			}
}
