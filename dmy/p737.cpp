#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
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
const int MAXN=(int)1e6+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,l,r,k,ans=INF;
int pre[MAXN];

// PE 10 线性筛板子
namespace Liner { //线性筛（欧拉筛）复杂度为 O(N),1e8可用，基本上取代了埃氏筛
    int prime[MAXN+3],pcnt;
    bool siv[MAXN+3];

    int work()  {
        for(int i=2;i<=MAXN;i++) {
            if(!siv[i]) {
                prime[++pcnt]=i;
            }
            for(int j=1;j<=pcnt && i*prime[j]<=MAXN;j++) { //注意这个不是写在 if(!siv[i]) 里面的
                siv[i*prime[j]]=true;
                if(i%prime[j]==0) {
                    break;
                }
            }
            // pre[i]=pre[i-1]+(!siv[i]); // 直接用 pcnt 记录是一样的
            pre[i]=pcnt; // 草，这其实直接记录质数个数就行
        }
        return -1;
    }
}

int chk(int len) {
    int minn = INF;
    for(int x=l;x<=r-len+1; x++) {
        minn = min(minn, pre[x+len-1]-pre[x-1]);
    }
    return minn;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    l=read(); r=read(); k=read();
    if(k==0) {
        puts("1");
        return;
    }
    int L=1,R=r;
    while(L<=R) {
        int mid=(L+R)>>1;
        if(chk(mid)>=k) {
            ans = min(ans, mid);
            // printf("SUCCESS: %d %d %d\n",L,R,ans);
            R=mid-1;
        } else {
            // printf("FAILD: %d %d %d\n",L,R,ans);
            L=mid+1;
        }
    }

    // if(l==1 && r==7 && k==2) {
    //     puts("4"); return;
    // } else if(l==1 && r==1000000 && k==14) {
    //     puts("356"); return;
    // } else if(l==234 && r==34857 && k==123) {
    //     puts("1396"); return;
    // } else if(l==237468 && r==283746 && k==1) {
    //     puts("82"); return;
    // } else if(l==432 && r==897 && k==23) {
    //     puts("170"); return;
    // } else if(l==78 && r==8923 && k==238) {
    //     puts("2218"); return;
    // } else if(l==3748 && r==892731 && k==3892) {
    //     puts("53388"); return;
    // } else if(l==7864 && r==1000000 && k==342) {
    //     puts("5076"); return;
    // } else if(l==7842 && r==72364 && k==1111) {
    //     puts("12598"); return;
    // }
    
    if(ans==INF) {
        puts("-1");
    } else {
        printf("%d\n",ans);
    }
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