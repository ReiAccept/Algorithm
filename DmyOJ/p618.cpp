#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS puts("YES")
#define NOO puts("NO")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)2e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,p,q,maxx,cans=0;
int pre[MAXN],ans[MAXN];
PII a[MAXN];

// ===================================================================================================================
// Seg Tree 板子
struct Node{
    int val,add,mul=1;
} t[MAXN<<2];

// int a[100003];

void build_t(int root,int l,int r)
{
    t[root].mul=1,t[root].add=0;
    if(l==r) t[root].val=0; //本题修改的地方,val=0 打标记用
    else
    {
        int m=(l+r)>>1,rx=root<<1;
        build_t(rx,l,m);
        build_t(rx+1,m+1,r);
        t[root].val=(t[rx].val+t[rx+1].val);
    }
}

void push_down(int root,int l,int r)
{
    int m=(l+r)>>1,rx=root<<1;
    t[rx].val=(t[rx].val*t[root].mul+t[root].add*(m-l+1));
    t[rx+1].val=(t[rx+1].val*t[root].mul+t[root].add*(r-m));//!!!!!!!!!!!!!!!!!!rx+1
    
    t[rx].mul=(t[rx].mul*t[root].mul);
    t[rx+1].mul=(t[rx+1].mul*t[root].mul);

    t[rx].add=(t[rx].add*t[root].mul+t[root].add);
    t[rx+1].add=(t[rx+1].add*t[root].mul+t[root].add);
    
    t[root].mul=1,t[root].add=0;
}

void up1(int root,int nowl,int nowr,int l,int r,ll k)
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        t[root].val=(t[root].val*k);
        t[root].mul=(t[root].mul*k);
        t[root].add=(t[root].add*k);
        return;
    }
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=root<<1;
    up1(rx,nowl,m,l,r,k);
    up1(rx+1,m+1,nowr,l,r,k);
    t[root].val=(t[rx].val+t[rx+1].val);
}

void up2(int root,int nowl,int nowr,int l,int r,ll k)
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        t[root].add=(t[root].add+k);
        t[root].val=(t[root].val+k*(nowr-nowl+1));
        return;
    }
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=root<<1;
    up2(rx,nowl,m,l,r,k);
    up2(rx+1,m+1,nowr,l,r,k);
    t[root].val=(t[rx].val+t[rx+1].val);
}

ll query(int root,int nowl,int nowr,int l,int r)
{
    if(r<nowl || nowr<l) return 0;
    if(l<=nowl && nowr<=r) return t[root].val;
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=root<<1;
    return (query(rx,nowl,m,l,r)+query(rx+1,m+1,nowr,l,r)); 
}

// End Seg Tree
// ============================================================================================


int que(int l,int r) {
    return l>r?0:pre[r]-pre[l-1];
}

bool chk(int m) {
    for(int i=m;i<=n;i++) {
        int mx=a[i].fi;
        if(mx*q*m<=p*que(i-m+1,i)) {
            return true;
        }
    }
    return false;
}

int cal(int mx, int sum) {
    return mx * q*maxx <= p * sum;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); 
    for(int i=1;i<=n;i++) {
        a[i].fi=read(); a[i].se=i;
    }
    p=read(); q=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        pre[i]=pre[i-1]+a[i].fi;
    }
    int l=0,r=n;
    while(l<r) {
        int m=(l+r)>>1;
        if(chk(m)) {
            maxx=max(maxx,m);
            l=m+1;
        } else {
            r=m;
        }
    }
    build_t(1,1,n);
    for (int i = maxx; i <= n; i++) {
        if (cal(a[i].fi, que(i - maxx + 1, i))) {
            //[i - m + 1 , i ] 这个区间是满足条件的，我们才开始二分
            int L = 1, R = i - maxx + 1, pos = INF;
            int sum = que(i - maxx + 1 + 1, i);//这里记录下 i 左边 m - 1 个数的和
            // for (int j = 1; j <= 50; j++) {
            while(L<=R) {
                int mid = (L + R) / 2;
                if (cal(a[i].fi , sum + a[mid].fi)) { // 最大的数是 a[i].val
                    pos = min(mid, pos);
                    R = mid-1;
                }
                else {
                    L = mid+1;
                }
            }
            up2(1,1,n,pos,i,1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (query(1,1,n,i,i) == 0) {
            ans[++cans]=a[i].se;
        }
    }
    sort(ans+1, ans+1+cans);
    printf("%lld\n",cans);
    for (int i=1;i<=cans;i++) {
        printf("%lld%c",ans[i]," \n"[i==cans]);
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