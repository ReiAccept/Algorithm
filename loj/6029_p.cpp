#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x) //scanf("%lld",&x) //When define int ll
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

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

/*
struct Node { //LOJ上CE,The source code compiled to 28818564 bytes, exceeding the size limit.
    int l=0,r=0,sum=0,maxx=-INF,minn=INF,tag=0,siz=0; //左边界,右边界,区间和,区间最大值,区间最小值,LazyTag,区间尺寸
    Node *lson=NULL,*rson=NULL; //左子树,右子树
}tr[MAXN<<2];
*/

struct Node {
    int l,r,sum,maxx,minn,tag,siz; //左边界,右边界,区间和,区间最大值,区间最小值,LazyTag,区间尺寸
    Node *lson,*rson; //左子树,右子树
}tr[MAXN<<2];
int a[MAXN];

void pushup(Node *rt) {
    rt->sum=rt->lson->sum+rt->rson->sum;
    rt->minn=min(rt->lson->minn,rt->rson->minn);
    rt->maxx=max(rt->lson->maxx,rt->rson->maxx);
}

void build(int nowl,int nowr,int rt) {
    tr[rt].l=nowl,tr[rt].r=nowr,tr[rt].siz=(nowr-nowl+1),tr[rt].minn=INF,tr[rt].maxx=-INF;
    if(nowl==nowr) {
        tr[rt].sum=tr[rt].maxx=tr[rt].minn=a[nowl];
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    tr[rt].lson=&tr[rx],tr[rt].rson=&tr[rx|1];
    build(nowl,nowm,rx); build(nowm+1,nowr,rx|1);
    pushup(&tr[rt]);
}

void node_add(Node *rt,int val) {
    rt->tag+=val;
    rt->sum+=rt->siz*val;
    rt->maxx+=val;
    rt->minn+=val;
}

void pushdown(Node *rt) {
    if(rt->tag) {
        node_add(rt->lson,rt->tag); node_add(rt->rson,rt->tag);
        rt->tag=0;
    }
}

int qry_min(int l,int r,Node *rt) {
    if(l>rt->r || r<rt->l) {
        return INF;
    }
    if(l<=rt->l && r>=rt->r) {
        return rt->minn;
    }
    pushdown(rt);
    return min(qry_min(l,r,rt->lson) , qry_min(l,r,rt->rson));
}

int qry_sum(int l,int r,Node *rt) {
    if(l>rt->r || r<rt->l) {
        return 0;
    }
    if(l<=rt->l && r>=rt->r) {
        return rt->sum;
    }
    pushdown(rt);
    return qry_sum(l,r,rt->lson) + qry_sum(l,r,rt->rson);
}

void up_add(int l,int r,Node *rt,int c) {
    if(l>rt->r || r<rt->l) {
        return;
    }
    if(l<=rt->l && r>=rt->r) {
        node_add(rt,c);
        return;
    }
    pushdown(rt);
    up_add(l,r,rt->lson,c); up_add(l,r,rt->rson,c);
    pushup(rt);
}

void up_div(int l,int r,Node *rt,int d) {
    if(l>rt->r || r<rt->l) {
        return;
    }
    if(l<=rt->l && r>=rt->r) {
        int fmin=rt->minn-(int)floor((double)(rt->minn)/d);
        int fmax=rt->maxx-(int)floor((double)(rt->maxx)/d);
        if(fmin==fmax) {
            node_add(rt,-fmin);
            return;
        }
    }
    pushdown(rt);
    up_div(l,r,rt->lson,d); up_div(l,r,rt->rson,d);
    pushup(rt);
}

inline void work(int CASE=1,bool FINAL_CASE=false) {
    int n=read(),q=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    build(1,n,1);
    while(q--) {
        int op=read(),l=read()+1,r=read()+1;
        if(op==1) {
            up_add(l,r,&tr[1],read());
        } else if(op==2) {
            up_div(l,r,&tr[1],read());
        } else if(op==3) {
            printf("%lld\n",qry_min(l,r,&tr[1]));
        } else if(op==4) {
            printf("%lld\n",qry_sum(l,r,&tr[1]));
        }
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}
