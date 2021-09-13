//立个Flag,养成不要使用using namespace std的习惯
#include<cstdio>
#include<algorithm>

const int INF=-0x3f3f3f3f;
int n,m,x;
int sum[200003],ans[200003];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sum[i]);
		sum[i]=sum[i]+sum[i-1];
		ans[i]=INF;
	}
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)//MDZZ这里有坑,第一次写成r=1然后坑了半天
			ans[r-l+1]=std::max(ans[r-l+1],sum[r]-sum[l-1]);
	for(int i=n-1;i>=1;i--)
		ans[i]=std::max(ans[i],ans[i+1]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
