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
#define YESS puts("YES")
#define NOO puts("NO")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e4+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

// 自己的 MillerRabin 板子
namespace MillerRabin { //对 1e18 的超大素数判定 ,需要 #define int long long
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
        while((tmp&1)==0) { //和 tmp%2==0 相同
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

// 严格鸽板子，觉得好看就存了 vector<int>fac = prime_fac::fac(n); 
namespace prime_fac {
    const int S = 8; // 随机算法判定次数，8~10 就够了
    long long mult_mod(long long a, long long b, long long c) {
        a %= c, b %= c;
        long long ret = 0;
        long long tmp = a;
        while (b) {
            if (b & 1) {
                ret += tmp;
                if (ret > c) ret -= c;
            }
            tmp <<= 1;
            if (tmp > c) tmp -= c;
            b >>= 1;
        }
        return ret;
    }

    // 快速幂
    long long qow_mod(long long a, long long n, long long _mod) {
        long long ret = 1;
        long long temp = a % _mod;
        while (n) {
            if (n & 1) ret = mult_mod(ret, temp, _mod);
            temp = mult_mod(temp, temp, _mod);
            n >>= 1;
        }
        return ret;
    }

    // 是合数返回true，不一定是合数返回false
    bool check(long long a, long long n, long long x, long long t) {
        long long ret = qow_mod(a, x, n);
        long long last = ret;
        for(int i = 1; i <= t; i++) {
            ret = mult_mod(ret, ret, n);
            if (ret == 1 && last != 1 && last != n - 1) return true;
            last = ret;
        }
        if (ret != 1) return true;
        return false;
    }

    // 是素数返回true，不是返回false
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    bool Miller_Rabin(long long n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if ((n & 1) == 0) return false;
        long long x = n - 1;
        long long t = 0;
        while ((x & 1) == 0) { x >>= 1; t++; }

        for(int i = 0; i < S; i++) {
            long long a = rng() % (n - 1) + 1;
            if (check(a, n, x, t))
                return false;
        }

        return true;
    }

    long long factor[100];// 存质因数
    int tol; // 质因数的个数，0~tol-1

    long long gcd(long long a, long long b) {
        long long t;
        while (b) {
            t = a;
            a = b;
            b = t % b;
        }
        if (a >= 0) return a;
        return -a;
    }

    long long pollard_rho(long long x, long long c) {
        long long i = 1, k = 2;
        long long x0 = rng() % (x - 1) + 1;
        long long y = x0;
        while (1) {
            i++;
            x0 = (mult_mod(x0, x0, x) + c) % x;
            long long d = gcd(y - x0, x);
            if (d != 1 && d != x) return d;
            if (y == x0) return x;
            if (i == k) { y = x0; k += k; }
        }
    }
    // 对n质因数分解，存入factor，k一般设置为107左右
    void findfac(long long n, int k) {
        if (n == 1) return;
        if (Miller_Rabin(n)) {
            factor[tol++] = n;
            return;
        }
        long long p = n;
        int c = k;
        while (p >= n) p = pollard_rho(p, c--);
        findfac(p, k);
        findfac(n / p, k);
    }
    vector<int> fac(long long n) {
        tol = 0;
        vector<int>ret;
        findfac(n, 107);
        for(int i = 0; i < tol; i++)ret.push_back(factor[i]);
        return ret;
    }
}

// for debug 我自己的板子
// namespace prime_fac2 {
//     // 是素数返回true，不是返回false
//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//     long long factor[100];// 存质因数
//     int tol; // 质因数的个数，0~tol-1

//     long long gcd(long long a, long long b) {
//         long long t;
//         while (b) {
//             t = a;
//             a = b;
//             b = t % b;
//         }
//         if (a >= 0) return a;
//         return -a;
//     }

//     long long pollard_rho(long long x, long long c) {
//         long long i = 1, k = 2;
//         long long x0 = rng() % (x - 1) + 1;
//         long long y = x0;
//         while (1) {
//             i++;
//             x0 = (MillerRabin::fast_mul(x0, x0, x) + c) % x;
//             long long d = gcd(y - x0, x);
//             if (d != 1 && d != x) return d;
//             if (y == x0) return x;
//             if (i == k) { y = x0; k += k; }
//         }
//     }
//     // 对n质因数分解，存入factor，k一般设置为107左右
//     void findfac(long long n, int k) {
//         if (n == 1) return;
//         if (MillerRabin::isprime(n)) {
//             factor[tol++] = n;
//             return;
//         }
//         long long p = n;
//         int c = k;
//         while (p >= n) p = pollard_rho(p, c--);
//         findfac(p, k);
//         findfac(n / p, k);
//     }
//     vector<int> fac(long long n) {
//         tol = 0;
//         vector<int>ret;
//         findfac(n, 107);
//         for(int i = 0; i < tol; i++)ret.push_back(factor[i]);
//         return ret;
//     }
// }

int tot;
int factor[MAXN];

int gcd(int a,int b){
    if (a==0) return 1;
    if (a<0) return gcd(-a,b);
    while (b){
        int t=a%b; a=b; b=t;
    }
    return a;
}
 
int Pollard_rho(int x,int c){
    int i=1,x0=rand()%x,y=x0,k=2;
    while (1){
        i++;
        x0=(MillerRabin::fast_mul(x0,x0,x)+c)%x;
        int d=gcd(y-x0,x); // 不能用 __gcd 哈哈
        if (d!=1 && d!=x){
            return d;
        }
        if (y==x0) return x;
        if (i==k){
            y=x0;
            k+=k;
        }
    }
}
 
void findfac(int n){
    if(n==1) {
        return;
    }
    if (MillerRabin::isprime(n)){
        factor[++tot] = n;
        return;
    }
    int p=n;
    while (p>=n) {
        p=Pollard_rho(p,rand() % (n-1) +1);
    }
    findfac(p); findfac(n/p);
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    int n=read();
    map<int,int> mp;
    // vector<int>fac = prime_fac2::fac(n); 
    // for(auto x:fac) {
    //     mp[x]++;
    // }
    findfac(n);
    for(int i=1;i<=tot;i++) {
        mp[factor[i]]++;
    }
    for(auto p : mp) {
        if (p.second >= 2) {
            YESS;
            return;
        }
    }
    NOO;
    return;
}

signed main() {
    srand(time(NULL));
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
        if(CASE!=T) {
            tot=0;
            mmst0(factor);
        }
    }
    return 0;
}

// 自己的板子 TLE6 换严格鸽的板子过了
// 找自己板子的问题不知道啥问题，最后发现 x0=(MillerRabin::fast_mul(x0,x0,x)+c)%x; 补全成了 x0=(MillerRabin::fast_pow(x0,x0,x)+c)%x;