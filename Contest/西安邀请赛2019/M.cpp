#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define P pair<ll,ll>
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f3f3f3f3f;//LLINF
const int N=(int)2e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Edge{
    int to,next,val;
    inline bool operator < (const Edge &x)const{
        return val> x.val;
    }
}edge[N];
int cnt;
int head[N];

void add(int u,int v,int val) //add u->v;
{
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].val=val;
    head[u]=cnt;
}

int n,m,c,d,e,ans;
int dis[N],num[N];

bool check(int mid)
{
    priority_queue<P,vector<P>,greater<P> >q;
    fill(dis,dis+n+1,INF);fill(num,num+n+1,INF);
    dis[1]=num[1]=0; 
    q.push(P(0,1));
    while(!q.empty())
    {
        P tmp =q.top();q.pop();
        int u=tmp.second;
        if(dis[u]<tmp.first) continue;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val && edge[i].val<=mid*d){
                dis[v] = dis[u] +edge[i].val;
                num[v] = min(num[v],num[u]+1);
                q.push(P(dis[v],v));
            }
        }
    }
    return (dis[n]<INF && num[n]<=mid*e) ;//可以走到n且走过的路径数目满足条件 
}

void work()
{
    n=read();m=read(); 
    c=read(); d=read(); e=read();
    for(int u,v,w,i=1;i<=m;i++)
    {
        u=read();v=read();w=read();
        add(u,v,w); add(v,u,w);
    }
    int l=1,r=100000;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans*c<<endl;
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