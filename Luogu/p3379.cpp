#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 500010

using namespace std;

struct Edge{
   int v,next;
}e[MAXN<<1];

int n,m,s,k;
int head[MAXN],d[MAXN],p[MAXN][23];
///head邻接表 d深度 p[i][j]存的[i]向上走2的j次方那么长的路径

void add(int u,int v)
{
    e[k].v=v;
    e[k].next=head[u];
    head[u]=k++;
}

void dfs(int u,int fa)
{
    d[u]=d[fa]+1;  //当前节点的深度为父节点深度+1
    p[u][0]=fa;  //2^0=1所以这个是向上走1的路径
    for(int i=1;(1<<i)<=d[u];i++) p[u][i]=p[p[u][i-1]][i-1];
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(v!=fa) dfs(v,u);
    }
}

int lca(int a,int b)
{
    if(d[a]>d[b]) swap(a,b);  //保证a的深度小于b,a在b上方
    for(int i=20;i>=0;i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];
    if(a==b) return a;
    for(int i=20;i>=0;i--)
    {
        if(p[a][i]==p[b][i]) continue;
        else a=p[a][i],b=p[b][i];
    }
    return p[a][0];
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}
