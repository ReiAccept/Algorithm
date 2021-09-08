#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
//using namespace __gnu_pbds; //If using pbds don't using std!
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
int f[MAXN],g[MAXN],siz[MAXN],fa[MAXN],tr[MAXN];
vector<int> grap[MAXN];

void dfs(int u)
{
    siz[u]=1,f[u]=0;
    for(auto v: grap[u])
    {
        if(v!=fa[u])
        {
            fa[v]=u;
            dfs(v);
            siz[u]+=siz[v];
            f[u]=f[u]+f[v]+siz[v]*(n-siz[v]);
        }
    }
}

int dfs2(int u,int rt,int s)
{
    if(u!=rt) g[u]=g[fa[u]]+f[fa[u]]-f[u]+(n-siz[u]-s)*(siz[u]+s)-siz[u]*(n-siz[u]);
    else g[u]=0;
    int res=f[u] + g[u];
    for(auto v: grap[u]) if(v!=fa[u]) res=min(res,dfs2(v,rt,s));
    return res;
}

inline void work()
{
    cin>>n;
    for(int i=2;i<=n;i++) fa[i]=-1; fa[1]=1;
    for(int u,v,i=1;i<=n-2;i++)
    {
        cin>>u>>v;
        grap[u].pb(v); grap[v].pb(u);
    }
    dfs(1);
    int s=siz[1],x=n-s;
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==-1)
        {
            tr[1]=fa[i]=i;
            dfs(i);
            break;
        }
    }
    cout<<dfs2(1,1,x)+dfs2(tr[1],tr[1],s)+s*x<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
