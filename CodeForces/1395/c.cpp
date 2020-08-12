#include<cstdio>

using namespace std;

int pa[209],pb[209];
int a[209][40],b[209][40],n,m,sum;
bool vis[209][209];

void readx(int r,char q)
{
    int x,cnt;
    for(int i=1;i<=r;i++)
    {
        scanf("%d",&x);
        cnt=32;
        if(q=='a')pa[i]=x;
        else pb[i]=x;
        while(x)
        {
            if(q=='a')a[i][cnt--]=x&1;
            else b[i][cnt--]=x&1;
            x>>=1;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    readx(n,'a');
    readx(m,'b');
    for(int k=0; k<=32; k++)
    {
        bool q=true,t;
        for(int i=1; i<=n; i++)if(a[i][k])
            {
                t=false;
                for(int j=1; j<=m; j++) if(!b[j][k] && !vis[i][j]) t=true;
                q&=t;
            }
        if(!q)continue;
        for(int i=1; i<=n; i++)
            if(a[i][k])
            {
                bool flag=0;
                for(int j=1; j<=m; j++) if(!b[j][k] && !vis[i][j]) flag=true;
                if(flag) for(int j=1; j<=m; j++) vis[i][j]|=(b[j][k]==1);
            }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(!vis[i][j])
            {
                sum|=pa[i]&pb[j];
                break;
            }
    printf("%d\n",sum);
    return 0;
}

