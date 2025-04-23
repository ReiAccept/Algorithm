#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n,m,ans;
bool vis[103][103];
char a[103][103];

void dfs(int x,int y)
{
    if(a[x][y]=='*' || vis[x][y])
        return;
    if(x<1 || x>n || y<1 || y>m)
        return;
    vis[x][y]=true;
    dfs(x-1,y-1);
    dfs(x-1,y);
    dfs(x-1,y+1);
    dfs(x,y-1);
    dfs(x,y+1);
    dfs(x+1,y-1);
    dfs(x+1,y);
    dfs(x+1,y+1);
}

int main()
{
qwq:
    cin>>n>>m;
    if(m==0)
        return 0;
    ans=0;
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j]=='@' && !vis[i][j])
            {
                dfs(i,j);
                ans++;
            }
    printf("%d\n",ans);
    goto qwq;
}
