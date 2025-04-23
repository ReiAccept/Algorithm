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
const int MAXN=(int)1e2+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};

int n;
int a[MAXN][MAXN],ans[MAXN][MAXN];

inline void work(int CASE,bool FINAL_CASE) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%1d",&a[i][j]);
            ans[i][j]=a[i][j];
        }
    }
    for(int i=1;i<n;i++) {
        ans[1][i+1] = a[1][i];
        ans[i+1][n] = a[i][n];
        ans[n][i] = a[n][i+1];
        ans[i][1] = a[i+1][1];
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%d",ans[i][j]);
        }
        puts("");
    }
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
