#include<cstdio>
#include<iostream>

using namespace std;

int n,m,ans,a,b,num=1;
int anss[100003];
char g[1003][1003];
int vis[1003][1003];

void dfs(int x,int y,char lat)
{
    if(g[x][y]==lat || vis[x][y] || x>n || x<1 || y>n || y<1) return;
    vis[x][y]=num;
    ans++;
    dfs(x+1,y,g[x][y]);
    dfs(x-1,y,g[x][y]);
    dfs(x,y+1,g[x][y]);
    dfs(x,y-1,g[x][y]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)for(int j=1; j<=n; j++) cin>>g[i][j];
    for(int i=1; i<=m; i++)
    {
        ans=0;
        scanf("%d%d",&a,&b);
        if(vis[a][b]) ans=anss[vis[a][b]];
        else dfs(a,b,'N');
        anss[num++]=ans;
        printf("%d\n",ans);
    }
    return 0;
}
