#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#define int long long//__int128
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

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
pair<int, int> a[MAXN];
int fa[MAXN],ans[MAXN],nxt[MAXN];
bool vis[MAXN];

vector<int> grap[MAXN];

int fid(int x) {
    return fa[x]==x?x:(fa[x]=fid(fa[x]));
}

int dfs(int x) {
    if(ans[x]!=0) return ans[x];
    ans[x]=1;
    if(nxt[x]) ans[x]+=dfs(nxt[x]);
    return ans[x];
}

inline void work(int Case=1) {
    mmst0(vis); mmst0(ans); mmst0(nxt);
    n=read();
    for(int i=1; i<=n; i++) {
        fa[i]=i;
        grap[i].clear();
    }
    for(int u,v,i=1; i<n; i++) {
        u=read(); v=read();
        grap[u].pb(v); grap[v].pb(u);
    }
    for(int i=1; i<=n; i++) {
        a[i].fi=i;
        a[i].se=read();
    }
    sort(a+1,a+1+n,[](pair<int, int> a,pair<int, int> b) {
        return a.se<b.se;
    });
    for(int i=1; i<=n; i++) {
        int x=a[i].fi;
        vis[x]=true;
        for(auto y : grap[x]) {
            if(vis[y]) {
                int fy=fid(y);
                if(x== fy) continue;
                nxt[fy]=x;
                fa[fy]=x;
            }
        }
    }
    for(int i=1; i<=n; i++) printf("%d\n",dfs(i));
    return;
}

signed main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
