#include<cstdio>
#include<iostream>

using namespace std;

int t,m;
int w[103],v[103];//w指要花费的时间,v指价值
int dp[105][1005];//dp[i][j]为以j容量,放入i个物品

int main()
{
    scanf("%d%d",&t,&m);//t时间m数目
    for(int i=1;i<=m;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=m;i++)
        for(int j=t;j>=0;j--)
            if(j>=w[i]) dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
    printf("%d\n",dp[m][t]);
    return 0;
}
