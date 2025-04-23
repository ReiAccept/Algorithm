#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
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
const int MAXN=(int)4e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
int fa[MAXN];
struct Edge {
    int u,v,w;
} e[MAXN];

int findx(int x) {
    return x==fa[x] ? x : fa[x]=findx(fa[x]);
}

bool merge(int u,int v) {
    u=findx(u),v=findx(v);
    return u==v ? false : fa[u]=v;
}

int chk(int mask) {
    for(int i=1;i<=n;i++) fa[i] = i;
    int size = n;
    for(int i=1;i<=m;i++) {
        if ((e[i].w | mask) == mask && merge(e[i].u, e[i].v)) {
            size--;
        }
    }
    return size == 1;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); m=read();
    for(int u,v,w,i=1;i<=m;i++) {
        e[i].u=read(); e[i].v=read(); e[i].w=read();
    }
    int ans=(1<<30)-1;
    for(int i=29;i>=0;i--) {
        ans ^= (1 << i);
        if (!chk(ans)) ans ^= (1 << i);
    }
    printf("%lld\n",ans);
    return;
}
//考虑每一位的贡献，从高到低用并查集判断在某一位全部为0时是否能够组成一棵树。如果可以，则禁用此位为1的所有边，继续向下查找。
//用并查集判断是否可以构成树（联通），如果所有节点的父亲节点相同，则图联通。
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