#include<iostream>

using namespace std;

struct Node
{
    int x,y;
    int fx;
}c,f;

char g[13][13];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
bool vis[13][13][4][13][13][4];

int dfs(int k)
{
    if(c.x==f.x && c.y==f.y) return k;
    if(vis[c.x][c.y][c.fx%4][f.x][f.y][f.fx%4])return 0;
    vis[c.x][c.y][c.fx%4][f.x][f.y][f.fx%4]=true;

    if(!g[c.x+dx[c.fx%4]][c.y+dy[c.fx%4]])c.fx++;
    else c.x+=dx[c.fx%4],c.y+=dy[c.fx%4];
    
    if(!g[f.x+dx[f.fx%4]][f.y+dy[f.fx%4]])f.fx++;
    else f.x+=dx[f.fx%4],f.y+=dy[f.fx%4];

    return dfs(k+1);
}

int main()
{
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='.')g[i][j]=true;
            if(ch=='F')f.x=i,f.y=j,g[i][j]=true;
            if(ch=='C')c.x=i,c.y=j,g[i][j]=true;
        }
    cout<<dfs(0)<<endl;
    return 0;
}
