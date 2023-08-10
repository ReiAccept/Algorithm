#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size())) // since C++20 std::ssize() is better
#define mkp(...) make_pair(__VA_ARGS__)
#define fi first
#define se second
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
const int MAXN=(int)1e5+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};

int n,k,cnt;
vector<pair<int,int> > p;

inline void work(int CASE,bool FINAL_CASE) {
    cin>>n>>k;
    for(int a,b,i=1;i<=n;i++) {
        cin>>a>>b;
        p.pb(mkp(a,b));
    }
    sort(p.rbegin(),p.rend());
    for(auto x:p) {
        if(k-x.se >= 0) {
            k-=x.se;
            cnt++;
        } else {
            break;
        }
    }
    cout<< (cnt==n ? 1 : p[cnt].fi+1) << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    signed T=1;// scanf("%d",&T);// cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) {
        work(CASE,CASE==T);
        if(CASE!=T) { }
    }
    return 0;
}
