#include<cstdio>

using namespace std;

int x,ans;
bool l[23][23],d[23];

void dfs(int n)
{
	if(n>x)
	{
		ans++;
		return;
	}
	for(int i=1;i<=x;i++)
		if(!d[i] && l[n][i])
		{
			d[i]=true;
			dfs(n+1);
			d[i]=false;
		}
}

int main()
{
	scanf("%d",&x);
	if(x<=0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=x;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		l[i][a]=l[i][b]=true;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
