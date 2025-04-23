// 原题 https://codeforces.com/contest/380/problem/C
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
const int MAXN=(int)1e5+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};
inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
int c[MAXN],rmq[MAXN][28];
char s[MAXN];

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); m=read();
    for(int i=1;i<=n;i++) {
        c[i]=c[i-1]+((s[i]=nc())==')');
        rmq[i][0]=rmq[i-1][0]+(s[i]=='('?1:-1);
    }
    for(int j=1;(1<<j)<=n;j++) {
        for(int i=1;i+(1<<j)-1<=n;i++) {
            rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
        }
    }
    while(m--)
    {
        int a=read(),b=read();
        int k=log2(b-a+1);
        printf("%d\n",((c[b]-c[a-1])+min(min(rmq[a][k],rmq[b-(1<<k)+1][k])-rmq[a-1][0],0))<<1);
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        work(CASE,CASE==T);
        if(CASE!=T) {}
    }
    return 0;
}
/*
对每个右括号，其匹配的左括号是固定的，保存每个右括号匹配的左括号位置，
对区间进行线扫描，标记扫描的区间右端点及其之前所有的右括号对应的左括号位置，
查询区间的标记个数就是答案，这个可以用线段树/树状数组维护。
当然这题也可以转化为 rmq 问题来 $O(nlogn)$ 预处理 $O(1)$查询，关键是代码更短
*/