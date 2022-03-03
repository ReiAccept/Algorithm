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
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,q;
int a[MAXN], b[MAXN], b_len;

struct ptree {
    int val, l, r;
} tree[MAXN * 24];
int root[MAXN], node_cnt;

void modify(int pre, int l, int r, int& now, int pos) {
    if(pos<l || pos>r) {
        return;
    } 
    tree[now = ++node_cnt] = {tree[pre].val + 1, tree[pre].l, tree[pre].r};
    if (l == r) {
        return;
    }
    int mid = (l+r)>>1;
    modify(tree[pre].l, l, mid, tree[now].l, pos); modify(tree[pre].r, mid + 1, r, tree[now].r, pos);
}

int query(int l, int r, int nowl, int nowr, int k) {
    int nowm=(nowl+nowr)>>1;
    return (nowl==nowr) ? (k>=nowl ? tree[r].val-tree[l].val : 0) : ((nowm>k) ? query(tree[l].l,tree[r].l,nowl,nowm,k) : (nowm==k ? tree[tree[r].l].val-tree[tree[l].l].val : tree[tree[r].l].val-tree[tree[l].l].val+query(tree[l].r,tree[r].r,nowm+1,nowr,k)));
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); q=read();
    for(int i=1;i<=n;i++) {
        b[i]=a[i]=read();
    }    
    sort(b+1,b+n+1);
    b_len = unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++) {
        modify(root[i-1],1,b_len,root[i],lower_bound(b+1,b +b_len+1,a[i])-b);
    }
    for(int i=1;i<=q;i++) {
        int l=read(),r=read(),h=read();
        printf("%d%c",query(root[l-1],root[r],1,b_len,upper_bound(b+1,b+b_len+1,h)-b-1)," \n"[i==q]);
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
        if(CASE==T) {
            break;
        }
        node_cnt=0; mmst0(root);
    }
    return 0;
}