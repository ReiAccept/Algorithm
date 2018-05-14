#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
const int size=100010;

int head[size],nxt[size],to[size],tot=0;
int low[size],dfn[size],dfs_clock=0;
int scccnt=0,sccnum[size],scctong[size];
stack<int> s;
int n,m;
int ff[size],tt[size],cd[size];

void build(int f,int t)
{
    to[++tot]=t;
    nxt[tot]=head[f];
    head[f]=tot;
}

void dfs(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    s.push(u);
    for(int i=head[u]; i; i=nxt[i])
    {
        int v=to[i];
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccnum[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        scccnt++;
        while(1)
        {
            int x=s.top();
            s.pop();
            sccnum[x]=scccnt;
            scctong[scccnt]++;

            if(x==u)
                break;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&ff[i],&tt[i]);
        build(ff[i],tt[i]);
    }
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            dfs(i);
    for(int i=1; i<=m; i++)
    {
        if(sccnum[ff[i]]!=sccnum[tt[i]])
            cd[sccnum[ff[i]]]++;
    }
    int ans=0,tot=0;
    for(int i=1; i<=scccnt; i++)
    {
        if(cd[i]==0)
        {
            ans+=scctong[i];
            tot++;
        }
    }
    if(tot==1)
        printf("%d",ans);
    else
        printf("%d",0);
    return 0;
}
