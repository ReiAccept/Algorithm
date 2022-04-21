//三倍经验
//https://codeforces.com/contest/559/problem/C
//https://atcoder.jp/contests/dp/tasks/dp_y
//http://oj.daimayuan.top/course/10/problem/467

#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
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
const int MAXN=(int)1e5+3,MOD=(int)1e9+7;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int h,w,m;
int x[MAXN],y[MAXN],dp[MAXN];
bool vis[MAXN];

// 组合数板子
#define mod MOD
ll fac[MAXN<<1],inv[MAXN<<1];
ll pow_mod(ll a,ll n) {
    ll ret =1;
    while(n) {
        if(n&1) ret=ret*a%mod;
          a=a*a%mod;
          n>>=1;
    }
    return ret;
}

void init() {
    fac[0]=1;
    for(int i=1;i<MAXN<<1;i++) {
        fac[i]=fac[i-1]*i%mod;
    }
}

ll Cc(ll x, ll y) {
    return fac[x]*pow_mod(fac[y]*fac[x-y]%mod,mod-2)%mod;
}
#undef mod
// 组合数板子

int dfs(int i) {
	if (vis[i]) return dp[i];
    vis[i]=true; //ATCoder ver -> if(dp[i]) return dp[i]; dont need vis 
	int res=0;
	for(int j=1;j<=m+1;j++) {
		if (j!=i && x[j]<=x[i] && y[j]<=y[i]) {
			res=(res+(dfs(j)*Cc(x[i]-x[j]+y[i]-y[j],x[i]-x[j]))%MOD)%MOD;
		}
	}
	return dp[i]=(Cc(x[i]-1+y[i]-1,x[i]-1)-res+MOD)%MOD;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    h=read(); w=read(); m=read();
    for(int i=1;i<=m;i++) {
        x[i]=read(); y[i]=read(); 
    }
    x[m+1]=h; y[m+1]=w;
    dfs(m+1);
    printf("%lld\n",dp[m+1]);
    return;
}

signed main() {
    init();
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}