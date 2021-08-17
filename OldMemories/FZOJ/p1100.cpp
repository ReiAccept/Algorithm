#include<cstdio>
#include<cstdlib>
#define Maxn 500

int min=Maxn,n,p,now;
int lb[Maxn][Maxn],f[Maxn];

void build(int a)
{
	for(int i=1;i<=lb[a][0];i++)
	{
		int j,t=lb[a][i];
		for(j=1;j<=lb[t][0];j++)
			if(lb[t][j]==a)
				break;
		lb[t][j]=lb[t][lb[t][0]];
		lb[t][0]--;
		build(t);
	}
	return;
}

void dfs(int c)
{
	bool flag=false;
	if(now>min)
		return;
	for(int i=1;i<=n;i++)
		if(f[i]==c)
			for(int j=1;j<=lb[i][0];j++)
			{
				int son=lb[i][j];
				f[son]=c+1;
				now++;
				flag=true;
			}
	now--;
	for(int i=1;i<=n;i++)
		if(f[i]==c+1)
		{
			f[i]=0;
			dfs(c+1);
			f[i]=c+1;
		}
	now++;
	for(int i=1;i<=n;i++)
		if(f[i]==c+1)
		{
			f[i]=0;
			now--;
		}
	if(!flag && now<min)
		min=now;
	return ;
}

int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=p;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lb[x][0]++;
		lb[x][lb[x][0]]=y;
		lb[y][0]++;
		lb[y][lb[y][0]]=x;
	}
	f[1]=1;
	build(1);
	now=1;
	dfs(1);
	printf("%d\n",min);
	return 0;
}
