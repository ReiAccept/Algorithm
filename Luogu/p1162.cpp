#include<iostream>

using namespace std;

int n;
int g[33][33];
bool vis[33][33];

void dfs(int x,int y)
{
    if(vis[x][y] || g[x][y]==1 || x>30 || x<0 || y>30 || y<0) return;
    vis[x][y]=true;
    g[x][y]=0;
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x-1,y);
}

int main()
{
    cin>>n;
    for(int i=0;i<=30;i++)for(int j=1;j<=30;j++) g[i][j]=2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int tmp;
            cin>>tmp;
            if(tmp)g[i][j]=1;
        }
    dfs(0,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
