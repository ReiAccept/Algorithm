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
const int MAXN=(int)2e3+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,k;
int a[MAXN],dp[MAXN][MAXN];

void work()
{
    while(cin>>n>>k)
    {
        mmst0(a);
        for(int i=1; i<=n; i++)a[i]=read();
        sort(a+1,a+n+1);
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                dp[i][j]=INF;
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int i=2; i<=n+1; i++)
            for(int j=1; j<=k; j++)
                dp[i][j]=min(dp[i-2][j-1]+(a[i-1]-a[i])*(a[i-1]-a[i]),dp[i-1][j]);
        cout<<dp[n][k]<<endl;
    }
        return;
}

    signed main()
    {
        //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
        signed T=1;//(int)read();
        for(signed Case=1; Case<=T; Case++)
        {
            //printf("Case %d: ",Case);
            work();
        }
        return 0;
    }
