#include <cstdio>

using namespace std;

int n,ans;
int ban[20][20],y[20],a[40],b[40];

void dfs(int i)
{
	if (i>n) 
	{
		ans++; 
		return;
	} 
	for(int j=1;j<=n;j++) 
		if (!(ban[i][j] || y[j] || a[i+j-1] || b[n-i+j] ))
		{
		y[j]=a[i+j-1]=b[n-i+j]=1;
		dfs(i+1);
		y[j]=a[i+j-1]=b[n-i+j]=0;        
		}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) 
			scanf("%d",&ban[i][j]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
