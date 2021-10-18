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
const int INF=0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)2e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

vector<pair<int,int> > G[MAXN<<1];
int d1[MAXN],d2[MAXN];
bool vis[MAXN];
int n,m;

void dijkstra(int x, ll *dis) {
	priority_queue <pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> > > q;
	mmst0(vis);
	q.push({ 0ll, x });
	dis[x] = 0;;
	while (!q.empty()) {
		pair<int,int> now = q.top();
		q.pop();
		int u = now.se;
		if (vis[u])
			continue;
		vis[u] = true;
		for (auto it : G[u]) {
			int v = it.se; ll w = it.fi;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({ dis[v], v });
			}
		}
	}
}

inline void work(int Case)
{
    scanf("%lld%lld", &n, &m);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int k, u, w;
		scanf("%lld %lld", &w, &k);
		cnt++;
		while (k--) {
			scanf("%d", &u);
			G[n + cnt].push_back({ w, u });
			G[u].push_back({ 0, n + cnt });
		    }
		}
		dijkstra(1, d1), dijkstra(n, d2); 
		printf("Case #%lld: ", Case);
		int ans = INF;
		for (int i = 1; i <= n; i++)ans=min(ans, max(d1[i], d2[i]));
		if (ans == INF) printf("Evil John\n");
		else {
			printf("%lld\n", ans);
			vector <int> v;
			for (int i = 1; i <= n; i++) 
                if (max(d1[i], d2[i]) == ans) v.push_back(i);
			for(int i = 0; i < (int)v.size() - 1; i++) printf("%lld ", v[i]);
			printf("%lld\n", v[(int)v.size() - 1]);
		}
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//
    scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        for (int i = 0; i < MAXN; i++) G[i].clear();
	    mmst3f(d1), mmst3f(d2);
        work(Case);
    }
    return 0;
}
