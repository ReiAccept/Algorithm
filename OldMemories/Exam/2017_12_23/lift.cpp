#include<cmath>
#include<cstdio>
#include<iostream>

#define M 1000000007

using namespace std;

int n,a,b,k;
long long f[2][5005],ans;
int l[5005],r[5005];

int main()
{
    freopen("lift.in", "r", stdin);
    freopen("lift.out", "w", stdout);

    scanf("%d%d%d%d",&n,&a,&b,&k);
    f[0][a]=1;
    int e=0,g=1;
    for(int i=1; i<=n; i++)
    {
        int dis=abs(i-b);
        l[i]=max(1,i-dis+1);
        r[i]=min(n,i+dis-1);
    }
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=n; j++)
            f[g][j]=0;
        for(int j=1; j<=n; j++)
        {
            (f[g][l[j]]+=f[e][j])%=M;
            (f[g][r[j]+1]-=f[e][j])%=M;
        }
        for(int j=1; j<=n; j++)
            (f[g][j]+=f[g][j-1])%=M;
        for(int j=1; j<=n; j++)
            f[g][j]-=f[e][j];
        swap(e,g);
    }
    for(int j=1; j<=n; j++)
        (ans+=f[e][j])%=M;
    ans=(ans+M)%M;
    cout<<ans<<endl;
    return 0;
}
//滚动数组,差值对DP优化
//时间上:每一次递推仅改变一个范围内的值,能用差值维护
//空间上:每一步仅与上一步有关,能用滚动数组
