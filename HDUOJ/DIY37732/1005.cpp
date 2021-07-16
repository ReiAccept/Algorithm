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
const int MAXN=(int)20;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int d[20];
int dp[20][10];
int dfs(int pos, int pre, int limit){
    if(pos == -1) return 1;
    if(!limit && dp[pos][pre] != -1) return dp[pos][pre];
    int up = limit ? d[pos] : 9;
    int tmp = 0;
    for(int i = 0; i <= up; i ++){
        if(pre == 6 && i == 2) continue;
        if(i == 4) continue;
        tmp += dfs(pos - 1, i, limit && d[pos] == i);
    }
    if(!limit) dp[pos][pre] = tmp;
    return tmp;
}

int solve(int x){
    int pos = 0;
    while(x){
        d[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos - 1, -1, 1);
}

void work()
{
    memset(dp, -1, sizeof(dp));
    int n,m;
    while(~scanf("%d%d" ,&n, &m) && (n || m)){
        printf("%d\n", solve(m) - solve(n - 1));
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
        //while(cin>>n)
        work();
    }
    return 0;
}
