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
const int MAXN=(int)1e6+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,q;
int a[MAXN];

struct Node {
    int lazy;
}tr[MAXN<<2];

void build(int nowl,int nowr,int rt) {
    // printf("%d %d %d\n",nowl,nowr,rt);
    if(nowl==nowr) {
        tr[rt].lazy=a[nowl];
        // printf("SET val:%d in rt:%d\n",tr[rt].lazy,rt);
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    build(nowl,nowm,rx); build(nowm+1,nowr,rx|1);
}

void pushdown(int rt) {
    int rx=rt<<1;
    tr[rx].lazy=max(tr[rx].lazy,tr[rt].lazy);
    tr[rx|1].lazy=max(tr[rx|1].lazy,tr[rt].lazy);
    tr[rt].lazy=0;
}

void modify(int target,int nowl,int nowr,int rt,int val) {
    if(nowl>target || nowr<target) {
        return;
    }
    if(nowl==nowr) {
        tr[rt].lazy=val;
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    pushdown(rt);
    modify(target,nowl,nowm,rx,val); modify(target,nowm+1,nowr,rx|1,val);
}

int query(int target,int nowl,int nowr,int rt) {
    if(nowl==nowr) {
        // printf("FIND val:%d in rt:%d\n",tr[rt].lazy,rt);
        return tr[rt].lazy;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    pushdown(rt);
    return nowm<target?query(target,nowm+1,nowr,rx|1):query(target,nowl,nowm,rx);
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    build(1,n,1);
    // for(int i=1;i<=n;i++) {
    //     printf("%d%c",query(i,1,n,1)," \n"[i==n]);
    // }
    q=read();
    while(q--) {
        if(read()==1) {
            int x=read(),y=read();
            modify(x,1,n,1,y);
        } else {
            tr[1].lazy=max(tr[1].lazy,read());
        }
    }
    for(int i=1;i<=n;i++) {
        printf("%d%c",query(i,1,n,1)," \n"[i==n]);
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
    }
    return 0;
}