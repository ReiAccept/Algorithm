#include<cstdio>
#include<cstring>

using namespace std;

int T,n;
int grap[203][203],dx[203];
bool vis[203];

bool findx(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && grap[x][i])
		{
			vis[i]=true;
			if(!dx[i] || findx(dx[i]))
			{
				dx[i]=x;
				return true;
			}
		}
	}
	return false;
}

bool checkx()
{
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(!findx(i))
			return false;
	} 
	return true;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(grap,0,sizeof(grap));
		memset(dx,0,sizeof(dx));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&grap[i][j]);
		if(checkx())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
/*
同行或者同列的点无论经过多少次变换仍然是同行或同列,所以这个问题转变为能否找到n和互相不同行或同列的点 
*/
