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
const int INF=0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;

// inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
// inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,q;
int a[MAXN];//tr_sum[MAXN<<2],tr_min[MAXN<<2],tr_min[MAXN<<2];
struct Node {
    int sum,minn,maxx,tag;
} tr[MAXN<<2];

inline void pushup(int rt) {
    Node *rtp=&tr[rt],*rxl=&tr[rt<<1],*rxr=&tr[(rt<<1)|1];
    rtp->maxx=max(rxl->maxx,rxr->maxx);
    rtp->minn=min(rxl->minn,rxr->minn);
    rtp->sum=rxl->sum+rxr->sum;
}

void build(int nowl,int nowr,int rt) {
    tr[rt].maxx=-INF,tr[rt].minn=INF;
    if(nowl==nowr) {
        tr[rt].minn=tr[rt].maxx=tr[rt].sum=a[nowl];
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    build(nowl,nowm,rx); build(nowm+1,nowr,rx|1);
    pushup(rt);
}

inline void node_add(int nowl,int nowr,int rt,int val) {
    tr[rt].tag+=val;
    tr[rt].sum+=val*(nowr-nowl+1);
    tr[rt].minn+=val;
    tr[rt].maxx+=val;
}

inline void pushdown(int nowl,int nowr,int rt) {
    if(tr[rt].tag) {
        int nowm=(nowl+nowr)>>1,rx=rt<<1;
        node_add(nowl,nowm,rx,tr[rt].tag); node_add(nowm+1,nowr,rx|1,tr[rt].tag);
        tr[rt].tag=0;
    }
}

void up_add(int nowl,int nowr,int l,int r,int rt,int c) {
    if(nowl>r || nowr<l) {
        return;
    }
    if(nowl>=l && nowr<=r) {
        node_add(nowl,nowr,rt,c);
        return;
    }
    pushdown(nowl,nowr,rt);
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    up_add(nowl,nowm,l,r,rx,c); up_add(nowm+1,nowr,l,r,rx|1,c);
    pushup(rt);
}

void up_div(int nowl,int nowr,int l,int r,int rt,int d) {
    if(nowl>r || nowr<l) {
        return;
    }
    if(nowl>=l && nowr<=r) { //递归到同一节点的fx,fy必定是相等的
        int fmin=tr[rt].minn-(int)floor((double)tr[rt].minn/d);
        int fmax=tr[rt].maxx-(int)floor((double)tr[rt].maxx/d);
        if(fmax==fmin) {
            node_add(nowl,nowr,rt,-fmin);
            return;
        }
    }
    pushdown(nowl,nowr,rt);
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    up_div(nowl,nowm,l,r,rx,d); up_div(nowm+1,nowr,l,r,rx|1,d);
    pushup(rt);
}

int qry_min(int nowl,int nowr,int l,int r,int rt) {
    if(nowl>r || nowr<l) {
        return INF; //维护最小值的时候这里记得return INF,其实在原本函数里if判断边界就可以避免这个问题
    }
    if(nowl>=l && nowr<=r) {
        return tr[rt].minn;
    }
    pushdown(nowl,nowr,rt);
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    return min(qry_min(nowl,nowm,l,r,rx),qry_min(nowm+1,nowr,l,r,rx|1));
}

int qry_sum(int nowl,int nowr,int l,int r,int rt) {
    if(nowl>r || nowr<l) {
        return 0;
    }
    if(nowl>=l && nowr<=r) {
        return tr[rt].sum;
    }
    pushdown(nowl,nowr,rt);
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    return qry_sum(nowl,nowm,l,r,rx)+qry_sum(nowm+1,nowr,l,r,rx|1);
}

inline void work(int Case=1) {
    n=read(); q=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    build(1,n,1);
    while(q--) {
        int op=read(),l=read()+1,r=read()+1;
        if(op==1) {
            up_add(1,n,l,r,1,read());
        } else if(op==2) {
            up_div(1,n,l,r,1,read());
        } else if(op==3) {
            printf("%lld\n",qry_min(1,n,l,r,1));
        } else if(op==4) {
            printf("%lld\n",qry_sum(1,n,l,r,1));
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
        work();
    }
    return 0;
}
