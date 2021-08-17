#include<cstdio>

using namespace std;

int n,clr[18];
bool p[38],vis[18];

void print()
{
	for(int j=1;j<=n;j++)
		printf("%d ",clr[j]);
	printf("\n");
}

void dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(p[clr[x-1]+i] && !vis[i])
		{
			clr[x]=i;
			vis[i]=true;
			if(x==n)
			{
				if(p[clr[n]+clr[1]])
					print();
			}
			else
				dfs(x+1);
			vis[i]=false;
		}
}

int main()
{
	scanf("%d",&n);
	p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=true;
	clr[1]=1;
	vis[1]=true;
	dfs(2);
	return 0;
}
