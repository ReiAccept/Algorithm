#include <iostream>
#include <cstring>
#include <cstdio>
#define Maxn 21

using namespace std;

char pic[Maxn][Maxn];
int m,n,idx[Maxn][Maxn],cnt;

void dfs(int i,int j);

int main()
{
    freopen("data.in","r",stdin);
    while(scanf("%d%d",&n,&m)==2 && m!=0 && n!=0 )
    {
        for(int i=0;i<m;i++)
            scanf("%s",pic[i]);
        cnt=0;
        memset(idx,0,sizeof(idx));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pic[i][j]=='@')
                    dfs(i,j);
        cout<<cnt<<endl;
    }
    return 0;
}

void dfs(int i,int j)
{
    if(idx[i][j] || pic[i][j]=='#')
        return;
    if(i<0 || j<0 || i>=m || j>=n)
        return;
    idx[i][j]=++cnt;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}