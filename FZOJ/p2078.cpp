#include<cstdio>

int n,k;
int a[105],f[105][105];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k-1;j++)
			f[i][j]=f[i-1][j];
		for(int j=0;j<=k-1;j++)
			f[i][(f[i-1][j]+a[i])%k]=(f[i][(f[i-1][j]+a[i])%k]>f[i-1][j]+a[i])?(f[i][(f[i-1][j]+a[i])%k]):(f[i-1][j]+a[i]);
	}
	printf("%d\n",f[n][0]);
}
