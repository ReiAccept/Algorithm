#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define PIS pair<int,string>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lowbit(x) (-x&x)
#define YESS puts("Yes")
#define NOO puts("No")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps=1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e6+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};
inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m,q,cnt;
struct Edge {
    int u,v,w;
} e[MAXN];
int val[MAXN],maxv[MAXN<<1],preMaxv[MAXN];

int dep[MAXN],siz[MAXN],son[MAXN],top[MAXN],fa[MAXN],dfn[MAXN],rnk[MAXN];
vector<PII> grap[MAXN];

int dfs1(int u) {
    son[u]=-1; siz[u]=1; dep[u]=dep[fa[u]]+1;
    for(auto [v,w]:grap[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;  siz[u]+=dfs1(v); val[v]=w; 
        if(son[u]==-1 || siz[son[u]]<siz[v])
            son[u]=v;
    }
    return siz[u];
}

inline int getIdx(int l, int r) {
    return l + r | l != r;
}

void dfs2(int u,int t) {
    top[u]=t;  dfn[u]=++cnt; rnk[cnt]=u;
    maxv[getIdx(dfn[u], dfn[u])] = val[u];
    if (son[u] == -1) return;
    preMaxv[son[u]]=max(preMaxv[u],val[son[u]]);
    dfs2(son[u],t); 
    // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
    for(auto [v,w] : grap[u]) {
        if(v!=fa[u] && v!=son[u]) {
            preMaxv[v] = val[v];
            dfs2(v,v);
        }
    }
}

int build(int l, int r) {
    if (l == r) {
        return maxv[getIdx(l, r)];
    }
    int mid = (l + r) / 2;
    return maxv[getIdx(l, r)] = max(build(l, mid), build(mid+1, r));
}

int query(int l, int r, int L, int R) {
    if(L <= l && r <= R) return maxv[getIdx(l, r)];
    int mid = (l + r) / 2;
    if(R <= mid) return query(l, mid, L, R);
    if(mid < L) return query(mid+1, r, L, R);
    return max(query(l, mid, L, R), query(mid+1, r, L, R));
}

// int lca(int u, int v) {
//     while (top[u] != top[v]) {
//         if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
//         else v = fa[top[v]];
//     }
//     return dep[u] > dep[v] ? v : u;
// }

int uffa[MAXN];
int findx(int x) {
    return x==uffa[x]?x:uffa[x]=findx(uffa[x]);
}

void merge(int u,int v) {
    u=findx(u),v=findx(v);
    uffa[u]=v;
}

int query(int x,int y) {
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = max(ans, preMaxv[x]);
        x = fa[top[x]];
    }
    if(x == y) {
        return ans;
    }
    if(dep[x] > dep[y]) swap(x, y);
    ans = max(ans, query(1, n, dfn[son[x]], dfn[y]));
    return ans;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); m=read();
    for(int i=1;i<=n;i++) {
        uffa[i]=i;
    }
    for(int i=1;i<=m;i++) {
        e[i].u=read(); e[i].v=read(); e[i].w=read();
    }
    sort(e+1,e+1+m,[](Edge a,Edge b){
        return a.w<b.w;
    });
    for(int i=1;i<=m;i++) {
        if(findx(e[i].u)!=findx(e[i].v)){
            grap[e[i].u].pb(mkp(e[i].v,e[i].w));
            grap[e[i].v].pb(mkp(e[i].u,e[i].w));
            merge(e[i].u,e[i].v);
        }
    }
    dfs1(1);  dfs2(1,1);
    build(1, n);
    q=read();
    for(int i=1;i<=q;i++) {
        int s=read(),t=read();
        printf("%d\n",query(s,t));
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        work(CASE,CASE==T);
        if(CASE!=T) {}
    }
    return 0;
}