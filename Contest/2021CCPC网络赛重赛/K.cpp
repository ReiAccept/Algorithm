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
const int MAXN=2e5 + 1009;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}


struct node {
	int id, v;
} a[MAXN];
vector<int> ver[MAXN];
int n, vis[MAXN], pre[MAXN], ans[MAXN], maxn[MAXN], nxt[MAXN];
int cmp(const node &a, const node &b) {
	return a.v < b.v;
}
int fid(int x) {
	return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
int dfs(int x) {
	if(ans[x] != 0) return ans[x];
	ans[x] = 1;
	if(nxt[x]) ans[x] += dfs(nxt[x]);
	return ans[x];
}

inline void work(int Case=1)
{
    n = read();
	memset(vis, 0, sizeof(int) * (n + 10));
	memset(ans, 0, sizeof(int) * (n + 10));
	memset(nxt, 0, sizeof(int) * (n + 10));
	for(int i = 1; i <= n; i++) {
		pre[i] = i;
		ver[i].clear();
	}
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		ver[x].push_back(y);
		ver[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		a[i].id = i;
		a[i].v = read();
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++) {
		int x = a[i].id;
		vis[x] = 1;
		for(auto y : ver[x]) if(vis[y]) {
			int fy = fid(y);
			if(x == fy) continue;
			nxt[fy] = x;
			pre[fy] = x;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		printf("%d\n", dfs(i));
	}
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
