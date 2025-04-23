#include<bits/stdc++.h>
//#define int long long//__int128
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
const int MAXN=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
double l, c, t, vr, vt1, vt2, d[105], dp[105];

void work()
{
    while(cin>>l>>n>>c>>t>>vr>>vt1>>vt2)
    {
        for(int i = 1; i <= n; i++ ) cin >> d[i];
        d[0]=0,d[n+1]=l,dp[0]=-t;
        for(int i = 1; i <= n + 1; i++ )
        {
            double mint=INF;
            for(int j = 0; j < i; j++ ){
                if(d[i]-d[j]<=c) dp[i] = dp[j] + t + ( d[i] - d[j] ) / vt1;
                else dp[i] = dp[j] + t + c / vt1 + ( d[i] - d[j] - c ) / vt2;
                mint=mint<dp[i]?mint:dp[i];
            }
            dp[i] = mint;
        }
        if(dp[n+1]<=l/vr) cout<<"What a pity rabbit!"<<endl;
        else cout <<"Good job,rabbit!"<<endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}