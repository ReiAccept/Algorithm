#include<cmath>
#include<cstdio>

#define mod 1000000007

using namespace std;
int n,a,b,k,ans;
long long f[5001][5001];
int sum[5001];
int main()
{
    freopen("lift.in","r",stdin);
    freopen("lift.out","w",stdout);
    scanf("%d%d%d%d",&n,&a,&b,&k);

    for(int i=1; i<=n; i++)
    {
        if(abs(a-i)<abs(a-b) && i!=a) //我们要满足条件就是和B层楼不冲突而且肯定不是自己家所在的A层
            f[i][1]=1;
        sum[i]=sum[i-1]+f[i][1];
    }
    //输入&维护差值数组

    for(int t=2; t<=k; t++)
    {
        for(int i=1; i<b; i++)
            f[i][t]=(f[i][t]+sum[(b+i+1)/2-1]-sum[i]+sum[i-1]+mod)%mod;

        for(int i=b+1; i<=n; i++)
            f[i][t]=(f[i][t]+sum[i-1]-sum[(b+i)/2+1-1]+sum[n]-sum[i]+mod)%mod;

        for(int i=1; i<=n; i++)
            sum[i]=(sum[i-1]+f[i][t])%mod;
    }
    for(int i=1; i<=n; i++)
        ans=(ans+f[i][k])%mod;
    printf("%d",ans);
}
