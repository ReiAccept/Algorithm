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
/*
原题在OpenJudge_2989
魔改背包问题,背包的体积取模,目标是缩小背包体积
f[i][j]表示前i个物品体积%k为j的最优值,得到状态转移方程。
每一次都要更新,每个数%k的值是不确定的。
(还在网上看到过一篇不一样的解法 https://blog.csdn.net/wx_t91/article/details/52713882 )
*/
