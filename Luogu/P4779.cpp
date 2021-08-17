#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
//#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar(x%10+'0');}

int n,m,s;//n-点数 m边数 s起点
bool vis[200003];
struct Edge{
    int to,dis,next;
}e[200003];
int head[200003],dis[200003],cnt;
void addedge(int u,int v,int d)//from u to v dis d(w);
{
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}

struct Node
{
    int dis,pos;
    bool operator < (const Node &x)const
    {
        return x.dis<dis;
    }
};
std::priority_queue<Node> q;//区别pbds的优先队列和std的优先队列 

void dij()
{
    dis[s]=0;
    q.push((Node){0,s});
    while(!q.empty())
    {
        Node t=q.top();
        q.pop();
        int x=t.pos,d=t.dis;
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].dis)
            {
                dis[y]=dis[x]+e[i].dis;
                if(!vis[y]) q.push((Node){dis[y],y});
            }
        }
    }
}

void work()
{
    n=read();m=read();s=read();
    for(int i=1;i<=n;i++) dis[i]=INF;
    for(int u,v,w,i=1;i<=m;i++)
    {
        u=read();v=read();w=read();
        addedge(u,v,w);
    }
    dij();
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
