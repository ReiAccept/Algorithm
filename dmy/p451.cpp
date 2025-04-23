#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)2e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
int a[MAXN],pre[MAXN];
//Begin HLD 板子
int cnt,dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],fa[MAXN],dfn[MAXN],rnk[MAXN];

vector<int> grap[MAXN];

int dfs1(int u) {
    son[u]=-1; siz[u]=1; dep[u]=dep[fa[u]]+1;
    pre[u]=pre[fa[u]]^a[u];
    for(auto v:grap[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;  siz[u]+=dfs1(v);
        if(son[u]==-1 || siz[son[u]]<siz[v])
            son[u]=v;
    }
    return siz[u];
}

void dfs2(int u,int t) {
    top[u]=t; dfn[u]=++cnt; rnk[cnt]=u;
    if (son[u] == -1) return;
    dfs2(son[u],t); 
    // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
    for(int v : grap[u]) {
        if(v!=fa[u] && v!=son[u])
            dfs2(v,v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
        else v = fa[top[v]];
    }
    return dep[u] > dep[v] ? v : u;
}
//End HLD 板子

int solve(int u,int v) {
    int c=lca(u,v);
    int f=fa[c];
    return (pre[u]^pre[f]^pre[c]^pre[v]);
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); m=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    for(int u,v,i=1;i<n;i++) {
        grap[u=read()].pb(v=read());
        grap[v].pb(u); 
    }
    dfs1(1);  dfs2(1,1);
    while(m--) {
        printf("%d\n",solve(read(),read()));
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}