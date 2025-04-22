#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int lt,sum,n,m,r;
int f[101][1001];
int Fish[101],t[101],mov[101],s[101];

void init()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&Fish[i]);
    for(int i=1; i<=n; i++) scanf("%d",&mov[i]);
    for(int i=1; i<n; i++) scanf("%d",&t[i]);
    scanf("%d",&m);
    memset(f,-1,sizeof(f));
    f[0][0]=0;
}

int main()
{
    init();
    for(int i=1; i<=n; i++)
    {
        r=s[0]=f[i][0]=0;
        while (lt+r<=m && Fish[i]>0)
        {
            r++;
            s[r]=s[r-1]+Fish[i];
            Fish[i]-=mov[i];
        }//计算待到几分钟的钓鱼数
        for(int j=1; j<=m; j++)
        {
            for(int k=0; k<=j-lt; k++)
            {
                if (j-k-lt<0)
                    break;
                if (f[i-1][j-k-t[i-1]]!=-1)
                    f[i][j]=max(f[i][j],f[i-1][j-k-t[i-1]]+s[min(k,r)]);//转移方程
            }
            sum=max(sum,f[i][j]);
        }
        lt+=t[i];//提前计算路程
    }
    printf("%d",sum);
}
