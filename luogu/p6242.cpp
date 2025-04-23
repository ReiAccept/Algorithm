#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
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
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)5e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Node {
    int l,r,sum,maxa,maxb,max_se,cnt; //左端点 , 右端点 , 区间和 , 区间最大值 , 区间历史最大值 , 区间次大值 , 区间最大值的个数
    int tma,tma1,tmb,tmb1; //tag_max_a 区间最大值加法标记 , tag_max_a1 区间非最大值加法标记  , tag_max_b 区间最大的历史最大值的加法的标记 ,tag_max_b1 区间非最大的历史最大值的加法的标记
    Node *lson,*rson;
}tr[MAXN<<2];
int a[MAXN];

void pushup(Node *rt) {
}

void build(int nowl,int nowr,int rt) {
    Node &rp=tr[rt];
    rp.l=nowl,rp.r=nowr;
    if(nowl==nowr) {
        rp.sum=rp.maxa=rp.maxb=a[nowl];
        rp.max_se=-INF;
        rp.cnt=1;
        return;
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    rp.lson=&tr[rx],rp.rson=&tr[rx|1];
    build(nowl,nowm,rx); build(nowm+1,nowr,rx|1);
    pushup(&tr[rt]);
}

inline void work(int CASE=1,bool FINAL_CASE=false) {
    int n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,n,1);
    while(m--) {
        int op=read(),l=read(),r=read();
        if(op==1) { //区间加 k
            int k=read();

        } else if(op==2) { //区间 a_i=min(a_i,v)
            int v=read();

        } else if(op==3) { //区间和

        } else if(op==4) { //求区间当前最大值

        } else if(op==5) { //求区间历史最大值

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
