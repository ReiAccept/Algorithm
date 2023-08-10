#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define PCI pair<char,int>
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
const int MAXN=(int)2e5+3,MOD=(int)1e9+7;

// inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;}; //fuck macOS
inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int a[MAXN],b[MAXN];

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    map<int,int> mp;
    auto n=read(),ans=0LL;
    for(auto i=1;i<=n;i++) {
        mp[b[i]=a[i]=read()]++;
    }
    sort(b+1,b+n+1);
    auto len=unique(b+1,b+n+1)-b-1;
    for(auto i=1;i<=len;i++) {
        ans+=mp[b[i]]*(mp[b[i]]-1)*(mp[b[i]]-2);
        for(auto j=1;j*j<=b[i] && b[i]*j<=b[len];j++) {
            auto query=[&](int x) {
                return mp.count(x) ? mp[x] : 0;
            };
            ans+=(!(b[i]%j)) && (j!=1) ? query(b[i])*query(b[i]/j)*query(b[i]*j) : 0;
            ans+=(!(b[i]%j)) && (j*j!=b[i]) ? query(b[i])*query(j)*query(b[i]*b[i]/j) : 0;
        }
    }
    printf("%lld\n",ans);
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        work(CASE,CASE==T);
        if(CASE!=T) {}
    }
    return 0;
}