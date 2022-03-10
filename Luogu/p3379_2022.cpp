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
const int MAXN=(int)5e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m,s;
int d[MAXN],p[MAXN][23];
vector<int> grap[MAXN];

void dfs(int u,int fa) { //d数组为深度(deep)，p数组为路径(path)
    d[u]=d[fa]+1; p[u][0]=fa;
    for(int i=1;(1<<i)<=d[u];i++) {
        p[u][i]=p[p[u][i-1]][i-1];
    }
    for(auto v : grap[u]) {
        if(v!=fa) {
            dfs(v,u);
        }
    }
}

int lca(int a,int b) {
    if(d[a]>d[b]) swap(a,b);
    for(int i=20;i>=0;i--) {
        if(d[a]<=d[b]-(1<<i)) b=p[b][i];
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--) {
        if(p[a][i]!=p[b][i]) {
            a=p[a][i]; b=p[b][i];
        }
    }
    return p[a][0];
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); m=read(); s=read();
    for(int x,y,i=1;i<n;i++) {
        grap[x=read()].pb(y=read()); grap[y].pb(x);
    }
    dfs(s,0);
    for(int i=1;i<=m;i++) {
        printf("%d\n",lca(read(),read()));
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