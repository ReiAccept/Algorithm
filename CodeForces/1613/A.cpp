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

int x1,p1,x2,p2;
int cnt1,cnt2;

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    x1=read(); p1=read(); 
    x2=read(); p2=read();
    // string s1=to_string(x1)+string(p1, '0'),s2=to_string(x2)+string(p2, '0');
    // if(s1.size()>s2.size()) {
    //     printf(">\n");
    //     return;
    // } else if(s1.size()<s2.size()) {
    //     printf("<\n");
    //     return;
    // } else if(s1.size()==s2.size()) {
    //     if(s1>s2) {
    //         printf(">\n");
    //         return;
    //     } else if(s1<s2) {
    //         printf("<\n");
    //         return;
    //     }
    // }
    int xx1=x1;
    while(xx1) {
        xx1/=10;
        p1++;
        cnt1++;
    }
    int xx2=x2;
    while(xx2) {
        xx2/=10;
        p2++;
        cnt2++;
    }
    // printf("%d %d\n",p1,p2);
    if(p1>p2) {
        printf(">\n");
        return;
    } else if(p1<p2) {
        printf("<\n");
        return;
    } else {
        int b=(to_string(x1).size()-to_string(x2).size());
        if(b<0) {
            x1*=pow(10,abs(b));
        } else if(b>0) {
            x2*=pow(10,b);
        }
        if(x1>x2) {
            printf(">\n");
            return;
        } else if(x1<x2) {
            printf("<\n");
            return;
        }
    }
    printf("=\n");
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}
