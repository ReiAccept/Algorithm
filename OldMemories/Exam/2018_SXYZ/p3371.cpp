#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

struct Edge{
    int to,val;
};

vector<Edge> G[100010];
int vis[100010];
int dis[100010];

const int INF=0x3f3f3f3f;

void add_edge(int u,int v,int d)
{
    Edge t;
    t.to=v,t.val=d;
    G[u].push_back(t);
}

void dijkstra(int s,int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        dis[i] = (i == s ? 0 : INF);
    for(int i = 0;i<n;i++)
    {
        int x, minn = INF;
        for(int j = 0;j<n;j++){
            if(!vis[j] && dis[j]<=minn)
            {
                x=j;
                minn=dis[j];
            }
        }
        vis[x] = 1;
        for(unsigned int j = 0;j<G[x].size();j++)
        {
            int y = G[x][j].to;
            int d = G[x][j].val;
            dis[y] = min(dis[y],dis[x]+d);
        }
    }
}

int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int f,g,w;
        scanf("%d%d%d",&f,&g,&w);
        add_edge(f,g,w);
    }
    dijkstra(s,n+1);
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]==0x3f3f3f3f?2147483647:dis[i]);
    return 0;
}
