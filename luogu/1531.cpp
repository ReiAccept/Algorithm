#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#define int long long//__int128
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
const int MAXN=(int)2e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Node {
    int n,s;
} tr[MAXN];

int n,m,a,b;
char op;

int findx(int l,int r,int maxx=-INF) {
    for(int i=l;i<=r;i++) {
        if(tr[i].s>maxx) {
            maxx=tr[i].s;
        }
    }
    return maxx;
}

inline void work(int Case=1) {
    // n=read(); m=read();
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>tr[i].s;
        tr[i].n=i;
    }
    while(m--) {
        // scanf("%c",&op);
        cin>>op;
        // int a=read(),b=read();
        cin>>a>>b;
        if(op=='Q') {
            printf("%d\n",findx(a,b));
        } else if(tr[a].s<b) {
            tr[a].s=b;
        }
    }
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