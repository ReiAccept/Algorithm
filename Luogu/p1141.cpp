#include<queue>
#include<cstring>
#include<iostream>

using namespace std;

int n,m,ans;
char g[1003][1003];
bool vis[1003][1003];

void dfs(int x,int y)
{
    vis[x][y]=true;
    ans++;
    char now=g[x][y];
    if(now!=g[x+1][y] && !vis[x+1][y] && x+1<=n) dfs(x+1,y);
    if(now!=g[x-1][y] && !vis[x-1][y] && x-1>=1) dfs(x-1,y);
    if(now!=g[x][y+1] && !vis[x][y+1] && y+1<=n) dfs(x,y+1);
    if(now!=g[x][y-1] && !vis[x][y-1] && y-1>=1) dfs(x,y-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        ans=0;
        int a,b;
        cin>>a>>b;
        dfs(a,b);
        cout<<ans<<endl;
    }
    return 0;
}
