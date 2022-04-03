#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define PIS pair<int,string>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lowbit(x) (-x&x)
#define YESS puts("possible")
#define NOO puts("impossible")
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

int n;
string s;
set<string>sst;
bool flag;
void dfs1(int st, int ed, string &a, string &b) {
    if (st > ed) {
        for (int i = 0; i < min(sz(a), sz(b)); i++) {
            if (a[i] != b[i]) {
                return;
            }
        }
        if (sz(a)> sz(b)) {
            sst.insert(a.substr(sz(b)));
        } else {
            sst.insert(b.substr(sz(a)));
        }
        return;
    }
    a.push_back(s[st]); dfs1(st + 1, ed, a, b); a.pop_back();
    b.push_back(s[st]); dfs1(st + 1, ed, a, b); b.pop_back();
}

void cal(string a, string b) {
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    for (int i = 0; i < min(sz(a), sz(b)); i++) {
        if (a[i] != b[i]) {
            return;
        }
    }
    string pre;
    if (sz(a)> sz(b)) {
        pre = (a.substr(sz(b)));
    } else {
        pre = (b.substr(sz(a)));
    }
    reverse(pre.begin(), pre.end());
    if (sst.count(pre)) {
        flag = true;
    }
}

void dfs2(int st, int ed, string &a, string &b) {
    if (flag) {
        return;
    }
    if (st > ed) {
        cal(a, b);
        return;
    }
    a.push_back(s[st]);  dfs2(st + 1, ed, a, b);
    a.pop_back();  b.push_back(s[st]);
    dfs2(st + 1, ed, a, b);  b.pop_back();
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    sst.clear(); flag=false;
    string tmp; cin >> tmp;
    n = tmp.size(); s = "?" + tmp;
    string a = "", b = "";
    dfs1(1, n / 2, a, b);
    dfs2(n / 2 + 1, n, a, b);
    if (flag) {
        YESS;
    } else {
        NOO;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//
    cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
        if(CASE!=T) {}
    }
    return 0;
}