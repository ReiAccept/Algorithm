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
const int MAXN=(int)1e6+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int a,b,c,d,n;
vector<int> v[55];

inline int gx(int x)
{
    int ans=0;
    while(x)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}

inline int calc(int x)
{
    int g=gx(x);
    return a*x*x*g + b*x*x + c*x*g*g + d*x*g;
}

inline void work()
{
    a=read();b=read();c=read();d=read();n=read();
    int ans=min(calc(1),calc(n));
    for(int i=1;i<=54;i++)
    {
        int pos=upper_bound(v[i].begin(),v[i].end(),n)-v[i].begin();
        if(pos) ans=min(ans,calc(v[i][pos-1]));
        if(v[i].size() && n>=v[i][0]) ans=min(ans,calc(v[i][0]));
        if(a*i+b == 0) continue;
        int x= -(c*i*i+d*i)/(a*i+b)/2;
        if(x>=1)
        {
            pos=lower_bound(v[i].begin(),v[i].end(),x) - v[i].begin();
            if(n >= x)
            {
                if(pos!=(int)v[i].size() && v[i][pos]<=n) ans=min(ans,calc(v[i][pos]));
                if(pos!=0 && v[i][pos]<=n) ans=min(ans,calc(v[i][pos-1]));
            }
        }
    }
    printf("%lld\n",ans);
    return;
}

signed main()
{
    for(int i=1;i<=MAXN;i++) v[gx(i)].pb(i);
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
