#include<bits/stdc++.h>

using namespace std;

const int N=2001;
int n,ans,x=N,y=N,Minx=N,Miny=N,Maxx=N,Maxy=N;
bool g[1+(N<<1)][1+(N<<1)];

void DFS(int x,int y)
{
    g[x][y]=true;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if(i!=j)
            {
                int nx=x+i,ny=y+j;
                if(nx>=Minx-2 && nx<=Maxx+2 && ny>=Miny-2 && ny<=Maxy+2 && !g[nx][ny]) DFS(nx,ny);
            }
}

int main()
{
    cin>>n;
    g[x][y]=true;
    for(int i=1;i<=n;i++)
    {
        char s;cin>>s;
        if(s=='N')
        {
            g[--x][y]=true;g[--x][y]=true;
            if(x<Minx) Minx=x;
        }
        if(s=='S')
        {
            g[++x][y]=true;g[++x][y]=true;
            if(x>Maxx) Maxx=x;
        }
        if(s=='E')
        {
            g[x][++y]=true;g[x][++y]=true;
            if(y>Maxy) Maxy=y;
        }
        if(s=='W')
        {
            g[x][--y]=true;g[x][--y]=true;
            if(y<Miny) Miny=y;
        }
    }
    for(int i=Minx-1;i<=Maxx+1;i++)
        for(int j=Miny-1;j<=Maxy+1;j++)
            if(!g[i][j])
            {
                ans++;
                DFS(i,j);
            }
    printf("%d\n",ans?ans-1:0);
    return 0;
}
