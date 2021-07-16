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

int dp[30][2];
int shu[20],num[30];
 
int dfs(int len,bool shi4,bool dao,bool ok)
{
    if(len <= 0) return ok;
    if(!dao && ok) return dao?shu[len]+1:shu[len];
    if(!dao && dp[len][shi4] != -1) return dp[len][shi4];
    int sum=0,over = dao?num[len]:9;
    for(int i = 0;i <= over;i++) sum += dfs(len-1,i==4,i==over&&dao,ok||(shi4&&i==9));
    if(!dao) dp[len][shi4] = sum;
    return sum;
 
}

void work()
{
    int n=read(),len=0;
    memset(num,0,sizeof(num));
    while(n)
    {
        num[++len] = n%10;
        n/= 10;
    }
    cout<<dfs(len,false,true,false)<<endl;
    return;
}

signed main()
{
    memset(dp,-1,sizeof(dp));
    shu[0] = 1;
    for(int i = 1;i < 20;i++) shu[i] = shu[i-1]*10;
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n)
        work();
    }
    return 0;
}
