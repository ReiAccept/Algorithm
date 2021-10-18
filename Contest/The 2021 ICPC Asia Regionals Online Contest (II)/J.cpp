#include<bits/stdc++.h>

using namespace std;

const int MAXN=503;

int n,m;
int grap[MAXN][MAXN],G[MAXN][MAXN];
int vis[MAXN][MAXN];
int x[4]={0,0,1,-1};
int y[4]={-1,1,0,0};

void dfs(int u,int v)
{
    vis[u][v]++;
    for(int i=0;i<4;i++)
    {
        int nowx=u+x[i];
        int nowy=v+y[i];
        if(nowx<1||nowx>n||nowy<1||nowy>n) continue;
        if(grap[nowx][nowy]>grap[u][v]) dfs(nowx,nowy);
    }
}

signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&grap[i][j]);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            //if(vis[i][j]==0) {
                dfs(i,j);
            //}
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<vis[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
