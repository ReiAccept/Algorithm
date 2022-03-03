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
const int MAXN=(int)103;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

vector<pair<int, int> > grap[MAXN];
int n, k, m, ans=INF;
int dp[MAXN][MAXN][MAXN][MAXN];

int f(int c, int s, int e, int t){
	if(~dp[c][s][e][t]) return dp[c][s][e][t];
	if(!t) return 0;
	int res = INF;
	for(auto j : grap[c]){
		if(j.se > c && j.se <= e){
			res = min(min(res, f(j.se, j.se, e, t-1) + j.fi), f(j.se, c+1, j.se, t-1) + j.fi);
		}
		if(j.se < c && j.se >= s){
			res = min(min(res, f(j.se, s, j.se, t-1) + j.fi), f(j.se, j.se, c-1, t-1) + j.fi);
		}
	}
	return dp[c][s][e][t] = res;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); k=read()-1; m=read();
	for(int i=1; i<=m; i++) {
		int u=read(), v=read(), c=read();
		grap[u].push_back(mkp(c, v));
	}
	memset(dp, -1, sizeof(dp));
	for(int i=1; i<=n; i++) {
		ans = min(min(ans, f(i, i, n, k)), f(i, 1, i, k));
	}
    printf("%d\n",ans>1e8?-1:ans);
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