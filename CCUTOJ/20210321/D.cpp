#include<bits/stdc++.h>

using namespace std;

int n,m,sx,sy;
char g[23][23];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void DFS(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]=='*' || g[x][y]=='v') return;
    if(!x)
    {
        cout<<"So dalao, Re Bu Qi."<<endl;
        exit(0);
    }
    g[x][y]='v';
    for(int i=0;i<4;i++) DFS(x+dx[i],y+dy[i]);
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='S') sx=i,sy=j;
        }
    DFS(sx,sy);
    cout<<"Man Shen Chuang Yi."<<endl;
    return 0;
}
