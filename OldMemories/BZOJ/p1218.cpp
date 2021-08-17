//李煜东_P11
#include<cstdio>

using namespace std;

int n,r,ans,sum[5003][5003];//前缀和优化

inline int maxx(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int main()
{
    scanf("%d%d",&n,&r);
    for(int i=1; i<=n; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        sum[x+1][y+1]+=z;
    }
    for(int i=1; i<=5001; i++)
        for(int j=1; j<=5001; j++)
            sum[i][j]+=sum[i-1][j];
    for(int i=1; i<=5001; i++)
        for(int j=1; j<=5001; j++)
            sum[i][j]+=sum[i][j-1];
    for(int i=r; i<=5001; i++)
        for(int j=r; j<=5001; j++)
            ans=maxx(ans,sum[i][j]+sum[i-r][j-r]-sum[i][j-r]-sum[i-r][j]);
    printf("%d\n",ans);
    return 0;
}
