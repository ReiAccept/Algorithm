#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int N=(int)1e6+10,mod=1e9+7;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m,k;
int inv[N]={0,1},c[N]={1};

int qpow(int a ,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}

void get_combine(int x)
{
    for(int i=1;i<=k;i++) c[i]=(c[i-1]*(x-i+1)%mod)*inv[i]%mod;
}

inline int calc(int x)
{
    return (c[x]*x%mod)*qpow(x-1,n-1)%mod;
}

void work()
{
    n=read();m=read();k=read();
    get_combine(m);
    int ans=c[k],ans1=0,flag=1;
    get_combine(k);
    for(int i=k;i>=1;i--)
    {
        ans1=(ans1+flag*calc(i)+mod)%mod;
        flag=-flag;
    }
    ans=ans*ans1%mod;
    cout<<ans<<endl;
    return;
}

signed main()
{
    for(int i=2;i<N;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
