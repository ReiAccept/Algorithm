#include<cstdio>
#include<iostream>

using namespace std;

bool G[1003][1003];
int x,y,n,k,ans,F[1003][1003];

int min3(int a,int b,int c)
{
	return min(min(a,b),c);
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			F[i][j]=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		G[x][y]=true;
		F[x][y]=0;
	}
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--)
			if(!G[i][j])
			{
				F[i][j]=min3(F[i+1][j],F[i+1][j+1],F[i][j+1])+1;
				if(F[i][j]>ans)
					ans=F[i][j];
			}
	printf("%d",ans);
	return 0;
}
