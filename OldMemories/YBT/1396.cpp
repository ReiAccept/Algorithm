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
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n, tot;
int indeg[30], ans[30], h[30];
bool v[30],grap[30][30];
string s[50010];

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    mmst3f(indeg);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 1; i < n; i++) {
        if (s[i] == s[i + 1] || s[i + 1].find(s[i]) == 0)
            continue;
        if (s[i].find(s[i + 1]) == 0) {
            puts("0");
            return;
        }
        int x = 0;
        while (s[i][x] == s[i + 1][x])
            x++;
        int a = s[i][x] - 'a' + 1, b = s[i + 1][x] - 'a' + 1;
        if (grap[b][a]) {
            puts("0");
            return;
        }
        grap[a][b] = true;
        if (!v[a]) {
            v[a] = true;
            indeg[a] = 0;
        }
        if (!v[b]) {
            v[b] = true;
            indeg[b] = 1;
        } else {
            indeg[b]++;
        }
    }
    queue<int> q;
    for(int i = 1; i < 30; i++)
        if (!indeg[i]) q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ans[++tot] = x;
        for(int i = 1; i < 30; i++) {
            if (grap[x][i] && !(--indeg[i])) {
                q.push(i);
            }
        }
    }
    for(int i = 1; i <= tot; i++)
        h[ans[i]] = i;
    string puz, res;
    cin >> puz;
    for(int i = 0; i < puz.length(); i++) {
        if (!h[puz[i] - 'a' + 1]) {
            puts("0");
            return;
        }
        res += (char)(h[puz[i] - 'a' + 1] + 'a' - 1);
    }
    cout << res << endl;
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


