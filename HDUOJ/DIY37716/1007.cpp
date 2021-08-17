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
const int MAXN=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
int a[MAXN][20],dp[MAXN][20];

void work()
{
    while(cin>>n && n)
    {
        mmst0(dp);mmst0(a);
        int tmp=-INF;
        for(int x,t,i=1; i<=n; i++)
        {
            x=read(),t=read();
            a[t][x]++;
            tmp=tmp>t?tmp:t;
        }
        for(int i=tmp; i>=0; i--)
            for(int j=0; j<=10; j++)
            {
                if(a[i][j]) dp[i][j]=max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1])+a[i][j];
                else dp[i][j]=max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
            }
        cout<<dp[0][5]<<endl;
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
