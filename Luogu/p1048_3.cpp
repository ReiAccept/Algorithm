#include<cstdio>
#include<algorithm>

using namespace std;

int t,m;
int w[103],v[103];
int f[1003];

int main()
{
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&w[i],&v[i]);
    for(int i=1;i<=m;i++)
        for(int j=t;j>=w[i];j--)
            f[j]=max(f[j-w[i]]+v[i],f[j]);//如果当前时间多于w[i],则考虑要不要拿这个w[i],比较f[j]也就是上一个物品i时候出现的结果(即不拿)和我用j-w[i]时间里最多可以拿的物品价值+当前物品的价值v[i]的价值总量哪个更大
    printf("%d\n",f[t]);
    return 0;
}
