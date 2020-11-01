#include <cstdio>

using namespace std;

int n,w[13];
bool vis[13];

void out()
{
	for(int i=1;i<=n;i++)
		printf("%d ",w[i]);
	printf("\n");
}

void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			w[x]=i;
			vis[i]=true;
			if(x==n)
				out();
			else
				dfs(x+1);
			vis[i]=false;
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
}
