#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%lld",&x) //When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("YES\n")
#define NOO printf("NO\n")
using namespace std;
// using namespace __gnu_pbds; //If using pbds don't using std!
typedef long long ll;
// typedef long double rld; //use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)3e5+3,MAXS=(int)1e6+3;

// inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
// inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
int a[MAXN],tr[MAXN<<2],d[MAXS],tr_max[MAXN<<2];

inline void pushup(int rt) {
    int rx=rt<<1;
    tr[rt]=tr[rx]+tr[rx|1];
    tr_max[rt]=max(tr_max[rx],tr_max[rx|1]);
}

void build(int nowl,int nowr,int rt) {
    // printf("DBG:NOWL:%lld NOWR:%lld\n",nowl,nowr);
    if(nowl==nowr) {
        tr_max[rt]=tr[rt]=a[nowl];
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    build(nowl,nowm,rx); build(nowm+1,nowr,rx|1);
    pushup(rt);
}

int qry(int nowl,int nowr,int l,int r,int rt) {
    if(nowl>r || nowr<l) {
        return 0;
    }
    if(nowl>=l && nowr<=r) {
        return tr[rt];
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    return qry(nowl,nowm,l,r,rx) + qry(nowm+1,nowr,l,r,rx|1);
}

void upd(int nowl,int nowr,int l,int r,int rt) {
    // printf("DBGqry:NOWL:%lld NOWR:%lld\n",nowl,nowr);
    if(nowl>r || nowr<l || tr_max[rt]<3) { //d[1]=1,d[2]=2 所以可以去掉
        return;
    }
    if(nowl==nowr) {
        tr_max[rt]=tr[rt]=d[tr[rt]];
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    upd(nowl,nowm,l,r,rx); upd(nowm+1,nowr,l,r,rx|1);
    pushup(rt);
}

inline void work(int Case=1) {
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,n,1);
    while(m--) {
        int t=read(),l=read(),r=read();
        if(l>r) swap(l,r);
        if(t==1) {
            upd(1,n,l,r,1);
        } else if(t==2) {
            printf("%lld\n",qry(1,n,l,r,1));
        }
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        for(int i=1;i<MAXS;i++) {
            for(int j=i;j<MAXS;j+=i) {
                d[j]++;
            }
        }
        work();
    }
    return 0;
}
