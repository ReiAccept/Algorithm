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
