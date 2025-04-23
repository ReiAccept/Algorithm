#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size())) // since C++20 std::ssize() is better
#define mkp(...) make_pair(__VA_ARGS__)
#define lowbit(x) ((-(x))&(x))
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<char,int> PCI;
typedef pair<int,string> PIS;

const double eps=1e-6;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const int MAXN=(int)3e5+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};

int n1,n2,m;
vector<int> g[MAXN];

inline void work(int CASE,bool FINAL_CASE) {
    cin>>n1>>n2>>m;
    for(int a,b,i=1;i<=m;i++) {
        cin>>a>>b;
        a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    vector<int> d(n1+n2,-1);
    d[0]=d[n1+n2-1]=0;
    queue<int> q;
    q.push(0); q.push(n1+n2-1);
    while(!q.empty()) {
        int v=q.front(); q.pop();
        for(auto u:g[v]) {
            if(d[u]==-1) {
                d[u]=d[v]+1;
                q.push(u);
            }
        }
    }
    cout << *max_element(d.begin(),d.begin()+n1) + *max_element(d.begin()+n1,d.end()) + 1 << endl;
    return;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    signed T=1;// scanf("%d",&T);// cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) {
        work(CASE,CASE==T);
        if(CASE!=T) { }
    }
    return 0;
}
