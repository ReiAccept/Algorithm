#include <cstdio>

#define Maxn 202

using namespace std;

int datas[Maxn],f[Maxn],net[Maxn],maps[Maxn][Maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&datas[i]);
        f[i]=datas[i];
    }

    int a,b;
    while(scanf("%d%d",&a,&b) && (a!=0||b!=0))
    {
        maps[a][b]=1;
    }
    for(int i=n-1;i>=1;i--)
    {
        int mint=0,k;
        for(int j=i+1;j<=n;j++)
        {
            if(maps[i][j] && f[j]>mint)
            {
                mint=f[j];
                k=j;
            }
        }
        if(mint>0)
        {
            f[i]+=mint;
            net[i]=k;
        }
    }
    int ans=f[1],k=1;
    for(int i=2;i<=n;i++)
    {
        if(f[i]>ans)
        {
            ans=f[i];
            k=i;
        }
    }
    printf("%d",k);
    while(net[k]>0)
    {
        printf("-%d",net[k]);
        k=net[k];
    }
    printf("\n%d\n",ans);
    return 0;
}
