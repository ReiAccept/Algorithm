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
#define YESS puts("Yes")
#define NOO puts("No")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)5e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,q;
int a[MAXN],b[MAXN];
int dp[MAXN][23];
PII p[MAXN];
// stack<PII> stk;
stack<int> stk;

// int BF(int l,int r) { // Just for test
//     int cnt=0;
//     stack<PII> s;
//     for(int i=l;i<=r;i++) {
//         while(s.size() && (p[i].fi==s.top().fi || p[i].se>=s.top().se)) {
//             s.pop();
//         }
//         s.push(p[i]);
//         if(s.size()==1) {
//             cnt++;
//         }
//     }
//     return cnt;
// }

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); q=read();
    for(int i=1;i<=n;i++) {
        p[i].fi=read();
    }
    for(int i=1;i<=n;i++) {
        p[i].se=read();
    }
    for(int i=1;i<=n+1;i++) {
        dp[i][0]=n+1;
    }
    for(int i=1;i<=n;i++) {
        while(stk.size() && (p[i].fi==p[stk.top()].fi || p[i].se>=p[stk.top()].se)) {
            dp[stk.top()][0]=i;
            stk.pop();
        }
        stk.push(i);

    }
    for(int j=1;j<=20;j++) {
        for(int i=1;i<=n+1;i++) {
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    while(q--) {
        int l=read(),r=read(),res=1;
        for(int i=20;i>=0;i--) {
            if(dp[l][i] && dp[l][i]<=r) { // if(dp[l][i]<=r) { 洛谷这样就能过，代码源OJ要这样加个小优化
                l=dp[l][i];
                res+=(1<<i);
            }
        }
        printf("%d\n",res);
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
        if(CASE!=T) {}
    }
    return 0;
}
// https://www.luogu.com.cn/blog/wsyear/solution-p8251

/*
令 dp_{i,j} 表示从 i 开始入栈，第 2^j 个 成功的二元组的编号。
通过一遍对题意得模拟我们可以求出对于所有的 i 的 dp_{i,0}。即当 i 把 j 弹出时，记录 dp_{j,0}=i
接着，预处理倍增数组，在 O(n\log n)的时间内求出所有的 dp_{i,j}
对于每次询问，枚举 i 从 \log n 到 0，看当前位往后 2^i 个成功的二元组的编号是否还在 [l,r] 区间内（类似倍增求 LCA）。单次询问时间复杂度 q\log n
最终时间复杂度 O(n\log n+q\log n)，可以通过本题。
*/