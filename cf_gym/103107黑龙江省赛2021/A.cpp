#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("YES\n")
#define NOO printf("NO\n")
using namespace std;
//using namespace __gnu_pbds; //If using pbds don't using std!
typedef long long ll;
//typedef long double rld; //use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)4e5+3;

// inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
// inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
int a[MAXN],tr[MAXN<<2],tr2[MAXN<<2];
char op[10];

inline void pushup(int rt) {
    int rx=rt<<1;
    tr[rt]=max(tr[rx],tr[rx|1]);
    tr2[rt]=tr2[rx] | tr2[rx|1];
}

void build(int nowl,int nowr,int rt) {
    if(nowl==nowr) {
        tr[rt]=tr2[rt]=a[nowl];
        return;
    }
    int m=(nowl+nowr)>>1,rx=rt<<1;
    build(nowl,m,rx); build(m+1,nowr,rx|1);
    pushup(rt);
}

void up1(int nowl,int nowr,int l,int r,int v,int rt) {
    if(nowl>r || nowr < l || (tr2[rt]&v)==tr2[rt]) {
        return;
    }
    if(nowr==nowl) {
        tr[rt]&=v;
        tr2[rt]=tr[rt];
        return;
    }
    int m=(nowl+nowr)>>1,rx=rt<<1;
    up1(nowl,m,l,r,v,rx); up1(m+1,nowr,l,r,v,rx|1);
    pushup(rt);
}

void up2(int nowl,int nowr,int x,int v,int rt) {
    if(nowl>x || nowr<x) {
        return;
    }
    if(nowl==nowr) {
        tr2[rt]=tr[rt]=v; //错误1,这里写成[nowl]了
        return;
    }
    int m=(nowl+nowr)>>1,rx=rt<<1;
    up2(nowl,m,x,v,rx); up2(m+1,nowr,x,v,rx|1);
    pushup(rt);
}

int qry(int nowl,int nowr,int l,int r,int rt) {
    if(nowl>r || nowr<l) {
        return 0;
    }
    if(nowl>=l && nowr<=r) {
        // printf("DBG:RET:nowl:%d nowr:%d rt:%d val:%d\n",nowl,nowr,rt,tr[rt]);
        return tr[rt];
    }
    int m=(nowl+nowr)>>1,rx=rt<<1;
    // printf("DBG:nowl:%d nowr:%d rt:%d\n",nowl,nowr,rt);
    return max(qry(nowl,m,l,r,rx),qry(m+1,nowr,l,r,rx|1));
}

inline void work(int Case=1) {
    scanf("%d%d",&n,&m);
    // printf("DBG:N:%d,M:%d\n",n,m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    while(m--) {
        scanf("%s",op);
        // printf("%s\n",op);
        if(op[0]=='A') {
            // int l=read(),r=read(),v=read();
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);
            up1(1,n,l,r,v,1);
        } else if(op[0]=='U') {
            // int x=read(),v=read();
            int x,v;
            scanf("%d%d",&x,&v);
            a[x]=v;
            up2(1,n,x,v,1);
        } else if(op[0]=='Q') {
            // int l=read(),r=read();
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",qry(1,n,l,r,1));
        }
    }
    return;
}

signed main() {
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
//https://codeforces.com/gym/103107/problem/A
//https://vjudge.net/solution/31455586