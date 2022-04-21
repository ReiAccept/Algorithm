#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
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
const int MAXN=(int)1e6+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
int a[MAXN];
int dp[MAXN][2]; // dp[i][1] 为第 i 个数在上升序列的最大值。dp[i][0] 为第 i 个数在下降序列的最大值。

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    for(int i=2;i<=n;i++) {
        int x=(a[i]>a[i-1]);
        dp[i][x]=max(dp[i-1][x^1],dp[i-1][x]+a[i-(x^1)]-a[i-x]);
        dp[i][x^1]=max(dp[i-1][0],dp[i-1][1]);
    }
    printf("%lld\n",max(dp[n][0],dp[n][1]));
    return;
}

// void slove() { // 我的不好懂，不如看这里严格鸽的 // https://zhuanlan.zhihu.com/p/494298933
//     cin >> n;
//     for(int i = 1; i <= n; i++)cin >> a[i];
//     for(int i = 2; i <= n; i++) {
//         if (a[i] > a[i - 1]) {
//             dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i] - a[i - 1]);
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
//         }
//         else {
//             //a[i] < a[i - 1]
//             dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + a[i - 1] - a[i]);
//             dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
//         }
//     }
//     cout << max(dp[n][0], dp[n][1]) << endl;
// }

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