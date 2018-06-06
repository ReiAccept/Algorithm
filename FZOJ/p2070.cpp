#include<cstdio>
#include<cstring>

int n,t;
int a[1010],dp[1010],sum[1010];

int main()
{
    scanf("%d%d",&n,&t);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    dp[1]=(a[1]-t)*(a[1]-t);
    dp[0]=0;
    for(int i=2;i<=n;++i)
        for(int j=i-1;j>=0;--j)
			dp[i]=(dp[i]<=dp[j]+(sum[i]-sum[j]-t)*(sum[i]-sum[j]-t))?dp[i]:dp[j]+(sum[i]-sum[j]-t)*(sum[i]-sum[j]-t);
    printf("%d\n",dp[n]);
    return 0;
}
/*
每组樱桃必须相邻,使美味度之和最小。很容易联想到其实和石子合并差不多,可以用区间划分来做。但是看一眼数据1000,O(n^3)的会T
那么应该怎么样优化呢,我们可以考虑,不采用区间划分,我们枚举有多少个樱桃,然后再枚举这个樱桃和最后几个樱桃组成一组。
弄一个前缀和(求甜度),我们可以用f[i]表示前i个樱桃的最少甜度那么,用j来枚举与第i个樱桃组成一组的樱桃的数量的开始,状态转移方程就出来了
f[i]=min(f[i],f[j]+(sum[i]-sum[j-1]-t)*(sum[i]-sum[j-1]-t));
*/
