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

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e7+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,k,ans;
int mp[MAXN],minp[MAXN];


// PE 10 线性筛板子
namespace Liner { //线性筛（欧拉筛）复杂度为 O(N),1e8可用，基本上取代了埃氏筛
    int prime[MAXN+3],pcnt;
    bool siv[MAXN+3];

    int work() {
        for(int i=2;i<=MAXN;i++) {
            if(!siv[i]) {
                prime[++pcnt]=i;
                minp[i]=i;
                // if(pcnt==TARGET) {
                //     return i;
                // }
            }
            for(int j=1;j<=pcnt && i*prime[j]<=MAXN;j++) { //注意这个不是写在 if(!siv[i]) 里面的
                siv[i*prime[j]]=true;
                minp[prime[j] * i] = prime[j];
                if(i%prime[j]==0) {
                    break;
                }
            }
        }
        return -1;
    }
}

// 2014 qpow 西安板子
int qpow(int a ,int b) 
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a;
        b>>=1;
        a=a*a;
    }
    return ans;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    n=read(); k=read();
    for(int i = 1; i <= n; i++) {
        int p = 1, q = 1;
        int val=read();
        while (val > 1) {
            int t = val%2 ==0 ? 2 :minp[val];
            int cnt = 0;
            while (val%t == 0) {
                cnt++; cnt %= k;
                val /= t;
            }
            p *= qpow(t, cnt);
            if (cnt)q *= qpow(t, k - cnt);
            if (q<0 || q > 10000000)q = 0;
        }
        ans += mp[q];
        mp[p]++;
    }
    printf("%lld\n",ans);
    return;
}

signed main() {
    Liner::work();
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