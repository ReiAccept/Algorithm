#include<iostream>

using namespace std;

struct BD
{
    int x,y;
}a[200003];

int h,w,p,q,ansx;
char g[2003][2003];

void dfs(int x,int y,int tx,int ty,int deep)
{
    if(deep>4) return;
    if(x==tx && y==ty)
        ansx=min(ansx,deep-1);
    if(g[x+1][y]=='.' && x+1<=h)
        dfs(x+1,y,tx,ty,deep+1);
    if(g[x-1][y]=='.' && x+1>=1)
        dfs(x-1,y,tx,ty,deep+1);
    if(g[x][y+1]=='.' && y+1<=w)
        dfs(x,y+1,tx,ty,deep+1);
    if(g[x][y-1]=='.' && y-1>=1)
        dfs(x,y+1,tx,ty,deep+1);
}


int main()
{
    ios::sync_with_stdio(false);
    cin>>h>>w>>p>>q;
    for(int i=1;i<=h;i++)
        for(int j=1;i<=w;j++)
            cin>>g[i][j];
    for(int i=1;i<=p;i++)
        cin>>a[i].x>>a[i].y;
    for(int i=1;i<=q;i++)
    {
        int a1,b1;
        ansx=0x3f3f3f3f;
        cin>>a1>>b1;
        dfs(a[a1].x,a[a1].y,a[b1].x,a[b1].y,0);
        cout<<ansx<<endl;
    }
    return 0;
}
