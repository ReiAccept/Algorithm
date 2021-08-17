#include<bits/stdc++.h>
//#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int N=(int)(100000 + 5020);

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Edge{
    int to,next,val;
    inline bool operator < (const Edge &x)const{
        return val> x.val;
    }
}edge[N];

int cnt=1;
int head[N];
bool vis[N];

void add(int u,int v,int val)//加入u->v的边
{
    edge[cnt].to=v;//
    edge[cnt].next=head[u];
    edge[cnt].val=val;
    head[u]=cnt++;//head[u]->cnt
}

int n,m,t;
int a[N],dis[N],co[N],dp[N];

priority_queue<Edge> q;
Edge cur,nex;
void dijkstra()
{
    mmst3f(dis);dis[1]=0; 
    cur.to=1;
    q.push(cur);
    while(!q.empty())
    {
        cur=q.top();q.pop();
        if(vis[cur.to]) continue;
        vis[cur.to]=true;
        for(int i=head[cur.to];i;i=edge[i].next){
            int u=edge[i].to;
            if(dis[u] > dis[cur.to]+edge[i].val){
                dis[u]=dis[cur.to]+edge[i].val;
                nex.to=u;
                nex.val=dis[u];
                q.push(nex);
            }
        }
    }
    for(int i = 1; i <= n; ++i)co[i] = dis[i];
}

void work()
{
    n=read();m=read();t=read();
    for(int i=2;i<=n;i++) a[i]=read();
    for(int i=1,u,v;i<=m;i++)
    {
        u=read(); v=read();
        add(u,v,2); add(v,u,2);
    }
    dijkstra();
    for(int i = 1; i <= n; ++i)for(int j = co[i]; j <= t; ++j)dp[j] = max(dp[j], dp[j - co[i]] + a[i]);
    for(int i = 1; i <= t; ++i)printf("%d ",dp[i]);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

