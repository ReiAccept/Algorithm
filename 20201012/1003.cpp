#include<bits/stdc++.h>

using namespace std;

char g[103][103];
int T,sx,sy,ex,ey,n,m,x,y;
int fx[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
bool vis[103][103];
bool flag,flag2;

struct Node
{
    int x,y,step;
} q[10000];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        flag=flag2=false;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                cin>>g[i][j];
                if(g[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if(g[i][j]=='E')
                {
                    ex=i;
                    ey=j;
                }
            }
        int head=1,tail=2;
        q[head].x=sx,q[head].y=sy,q[head].step=0,vis[sx][sy]=true;
        while(head<tail)
        {
            for(int i=0; i<4; i++)
            {
                int x=q[head].x+fx[i][0],y=q[head].y+fx[i][1];
                if(x<1 || x>n || y<1 || y>m) continue;
                if(g[x][y]!='#' && !vis[x][y])
                {
                    vis[x][y]=1;
                    q[tail].x=x;
                    q[tail].y=y;
                    q[tail++].step=q[head].step+1;
                }
                if(x==ex && y==ey)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                cout<<q[tail-1].step<<endl;
                flag2=true;
                break;
            }
            head++;
        }
        if(!flag2)cout<<"-1"<<endl;
    }
    return 0;
}
//我是脑残,没看数据就dfs==浪费时间我是傻逼
