#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
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

namespace MillerRabin { //对 1e18 的超大素数判定
    inline int fast_mul(int x,int y,int p) { //不快，防爆用
        return (__int128)x*y%p;
    }
    int fast_pow(int x,int y,int p) { //return x^y mod p
        long long ans=1;
        while(y) {
            if(y&1) {
                ans=fast_mul(ans,x,p);
            }
            x=fast_mul(x,x,p);
            y>>=1;
        }
        return ans;
    }
    bool isprime(int n) {
        if(n<=1) {
            return false;
        }
        static const int pr[]={2,3,5,7,11,13,17,19,23,29,31,37};
        for(auto a:pr) {
            if(n%a==0) {
                return n==a;
            }
        }
        int tmp=n-1,l=0;
        while((tmp&1)==0) { //和 tmp/2==0 相同
            tmp>>=1;
            l++;
        }
        for(auto a:pr){
            int x=fast_pow(a,tmp,n);
            if(x==1||x==n-1) {
                continue;
            }
            int j=0;
            while(++j<l){
                x=fast_mul(x,x,n);
                if(x==n-1) {
                    break;
                }
            }
            if(j>=l) {
                return false;
            }
        }
        return true;
    }
    int work(int TARGET) {
        int cnt=0;
        for(int i=0;i<=MAXN;i++) {
            if(isprime(i)) {
                cnt++;
                if(cnt==TARGET) {
                    return i;
                }
            }
        }
        return -1;
    }   
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    int x;
    while(scanf("%lld",&x)!=EOF) {
        printf("%c\n","NY"[MillerRabin::isprime(x)]);
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
