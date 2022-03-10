#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define PII pair<int,int>
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
const int MAXN=(int)1e6+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct node{int to,w;};
vector <node> mp[MAXN];

inline bool operator < (node a,node b){return a.w>b.w;}
inline bool operator > (node a,node b){return a.w<b.w;}
priority_queue <node> q;

int n,m,t,r,k,A[MAXN],d[25][MAXN],id[MAXN],dp[MAXN][25],ct[MAXN];
bool vis[25][MAXN];
double DP[MAXN][25],P[MAXN];

inline void dij(int id,int uu) {
    for(int i=1;i<=n;i++) {
        d[id][i]=INF; 
    }
    q.push({uu,0}); 
    d[id][uu]=0;
    while(!q.empty()) {
        node u=q.top(); q.pop();
        if(vis[id][u.to]) {
            continue;
        }
        d[id][u.to]=u.w;  vis[id][u.to]=1;
        for(auto v : mp[u.to]) {
            if(d[id][v.to]>d[id][u.to]+v.w) {
                d[id][v.to]=d[id][u.to]+v.w;
                q.push({v.to,d[id][v.to]});
            }
        }
    }
}

inline double DFS(int sta,int u) {
    if(DP[sta][u]) return DP[sta][u];
    double tmp=1.0*P[u]*d[u][n]/t+(1-P[u])*d[u][n]/r;
    for(int i=1;i<=k;i++) {
        if(sta&(1<<(i-1))) continue;
        tmp=min(tmp,1.0*(1-P[u])*d[u][n]/r+P[u]*(1.0*d[u][A[i]]/t+DFS(sta|(1<<(i-1)),i)));
    }
    return DP[sta][u]=tmp;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    t=read(); r=read(); n=read(); m=read();
    for(int i=1;i<=m;i++) {
        int u=read(),v=read(),w=read();
        mp[u].pb((node){v,w}); mp[v].pb((node){u,w});
    }
    k=read();
    for(int i=1;i<=k;i++) A[i]=read(),P[i]=read()/100.0,dij(i,A[i]),id[A[i]]=i;
    dij(19,1); dij(20,n); P[19]=1;
    if(d[19][n]==INF) {
        puts("-1"); 
        return;
    }
    DFS(0,19); 
    int ed=(1<<k)-1;
    printf("%.6f\n",DP[0][19]);
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