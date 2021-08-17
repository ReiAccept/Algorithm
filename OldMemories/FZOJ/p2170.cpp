#include<cstdio>
#include<iostream>

using namespace std;

int T,n,m;
int a[1005][1005];
long long f[1005][1005];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				f[i][j]=max(f[i-1][j+1]+a[i][j],max(f[i-1][j],f[i][j+1]));
		printf("%lld\n",f[n][1]);
	}
	return 0;
}
//BZOJ3997
