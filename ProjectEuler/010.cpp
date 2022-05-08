#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long //__int128
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
const int MAXN=(int)2000000;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

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

namespace Euler { //线性筛（欧拉筛）复杂度为 O(N),1e8可用，基本上取代了埃氏筛
    int prime[MAXN+3],pcnt;
    bool siv[MAXN+3];

    int work()  {
        for(int i=2;i<=MAXN;i++) {
            if(!siv[i]) {
                prime[++pcnt]=i;
                // if(pcnt==TARGET) {
                //     return i;
                // }
            }
            for(int j=1;j<=pcnt && i*prime[j]<=MAXN;j++) { //注意这个不是写在 if(!siv[i]) 里面的
                siv[i*prime[j]]=true;
                if(i%prime[j]==0) {
                    break;
                }
            }
        }
        return -1;
    }
}

inline void work(int Case=1) {
    int ans=0;
    for(int i=1;i<=MAXN;i++) {
        if(MillerRabin::isprime(i)) {
            ans+=i;
        }
    }
    prt(ans); puts("");
    ans=0;
    Euler::work();
    for(int i=1;i<=Euler::pcnt;i++) {
        ans+=Euler::prime[i];
    }
    prt(ans); puts("");
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