#include<cstdio>

using namespace std;

int n,m,t,sx,sy,fx,fy,ans;
bool g[6][6],vis[6][6];

void dfs(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m || g[x][y] || vis[x][y]) return;
    if(x==fx && y==fy)
    {
        ans++;return;
    }
    vis[x][y]=true;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    vis[x][y]=false;
}

int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    for(int i=1;i<=t;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=true;
    }
    dfs(sx,sy);
    printf("%d\n",ans);
    return 0;
}
