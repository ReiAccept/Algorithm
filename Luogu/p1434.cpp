#include<cstdio>
#include<iostream>

using namespace std;

int r,c,ans;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int g[103][103],dis[103][103];

int dfs(int x,int y)
{
    if(dis[x][y]) return dis[x][y];
    dis[x][y]=1;
    for(int f=0;f<=3;f++)
    {
        int xx=dx[f]+x,yy=dy[f]+y;
        if(xx>=1 && xx<=r && yy>=1 && yy<=c && g[xx][yy]<g[x][y])
        {
            dfs(xx,yy);
            dis[x][y]=max(dis[x][y],dis[xx][yy]+1);
        }
    }
    return dis[x][y];
}

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&g[i][j]);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            ans=max(ans,dfs(i,j));
    cout<<ans<<endl;
    return 0;
}
//这个题目一开始理解错题意了
//题意是一个点为1让你找最多可以过几个点
