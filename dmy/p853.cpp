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

const double eps=1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e5+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};
inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m,x,y,ans;
PII p[MAXN];

void mergesort(int l, int r) {
    static int tmp[MAXN];
    if(l>=r) {
        return;
    }
    int mid=(l+r)>>1,j=mid+1,tail=0;
    mergesort(l, mid); mergesort(j, r);
    for(int i=l;i<=mid;i++) {
        int k=(mid-i+1);
        while (j<=r && p[j].se<p[i].se) {
            tmp[++tail]=p[j++].se;
            ans+=k;
        }
        tmp[++tail]=p[i].se;
    }
    while(j<=r) {
        tmp[++tail]=p[j++].se;
    }
    for (int i=1;i<=tail;i++) {
        p[l+i-1].se=tmp[i];
    }
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); m=read(); x=read(); y=read();
    ans=(x+1)*(y+1);
    for(int i=1;i<=x;i++) {
        p[i].fi=read(); p[i].se=read();
    }
    sort(p+1,p+1+x);
    mergesort(1, x);
    for(int i=1;i<=y;i++) {
        p[i].fi=read(); p[i].se=read();
    }
    sort(p+1,p+1+y);
    mergesort(1, y);
    printf("%lld\n",ans);
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