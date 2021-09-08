#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
//using namespace __gnu_pbds; //If using pbds don't using std!
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int a[MAXN],b[MAXN];

inline void work()
{
    int n=read(),m=read(),ans=0; b[0]=-INF;b[m+1]=INF;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    sort(a+1,a+1+n); sort(b+1,b+1+m);
    for(int i=0;i<=m;i++)
    {
        int lf=upper_bound(a+1,a+1+n,b[i])-a;
        int rf=lower_bound(a+1,a+1+n,b[i+1])-a-1;
        ans=max(ans,rf-lf+1);
    }
    if(ans<=0) printf("Impossible\n");
    else printf("%lld\n",ans);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
