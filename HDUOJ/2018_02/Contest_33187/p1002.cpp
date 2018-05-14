#include<cstdio>
#include<iostream>

using namespace std;

int Case,tmp,n,ans;
bool a[53][53];
bool vis[53];

void dfs(int x,int deep)
{
    //printf("%d %d\n",x,deep);
    if(deep==4)
    {
        ans++;
        return;
    }
    for(int i=1; i<=n; i++)
        if(a[x][i] && !vis[i])
        {
            vis[i]=true;
            dfs(i,deep+1);
            vis[i]=false;
        }
}

int main()
{
    scanf("%d",&Case);
    while(Case--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                scanf("%1d",&tmp);
                a[i][j]=tmp;
            }
        for(int i=1;i<=n;i++)
        {
            vis[i]=true;
            dfs(i,1);
            vis[i]=false;
        }
        printf("%d\n",ans);
    }
    return 0;
}
