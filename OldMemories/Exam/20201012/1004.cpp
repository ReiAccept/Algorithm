#include <bits/stdc++.h>
#define ll long long
#define Mid ((l+r)>>1)
#define lson (rt<<1)
#define rson (rt<<1|1)
#define ull unsigned long long
using namespace std;
const int N=3e5+1009;
int read()
{
    char c;
    int num,f=1;
    while(c=getchar(),!isdigit(c))if(c=='-')f=-1;
    num=c-'0';
    while(c=getchar(), isdigit(c))num=num*10+c-'0';
    return num*f;
}
struct node
{
    int x,v;
};
int n,m,s,e,d[N];
int head[N],nxt[N],ver[N],edge[N],tot=1;
priority_queue<node>q;
void add(int u,int v,int w)
{
    ver[++tot]=v;
    nxt[tot]=head[u];
    head[u]=tot;
    edge[tot]=w;
}
bool operator<(const node &x,const node &y)
{
    return x.v>y.v;
}
void dijkstra(int x)
{
    while(q.size()) q.pop();
    memset(d,0x3f,sizeof(d));
    d[x]=0;
    q.push((node){x,0});
    while(q.size())
    {
        int w=q.top().v;x=q.top().x;
        q.pop();
        if(w>d[x])continue;
        for(int i=head[x]; i; i=nxt[i])
        {
            if(d[ver[i]]>d[x]+edge[i])
            {
                d[ver[i]]=d[x]+edge[i];
                q.push((node){ver[i],d[ver[i]]});
            }
        }
    }
}

int main()
{
    n=read();m=read();s=read();e=read();
    for(int i=1; i<=m; i++)
    {
        int u=read(),v=read(),w=read();
        add(u,v,w); add(v,u,w);
    }
    dijkstra(s);//happy板子
    printf("%d\n", d[e]);
    return 0;
}
//贴以前写过的板子
