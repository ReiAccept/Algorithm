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
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e6+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Node
{
    int cnt, sum, sqr;
    Node()
    {
        cnt = -1;
        sum = sqr = 0;
    }
    Node(int _cnt, int _sum, int _sqr): cnt(_cnt), sum(_sum), sqr(_sqr){}
}F[20][10][10];

int dig[20];
int m[20];
int a, b, n;

Node dfs(int pos, int sum1, int sum2, bool lim)
{
    if (pos == -1)
    {
        if (sum1 != 0 && sum2 != 0) return Node(1, 0, 0);
        return Node(0, 0, 0);
    }
    if (!lim && F[pos][sum1][sum2].cnt != -1) return F[pos][sum1][sum2];
    int up = lim ? dig[pos] : 9;
    Node ans(0, 0, 0), tmp;
    for (int i = 0;i <= up;i++)
    {
        if (i == 7) continue;
        tmp = dfs(pos-1, (sum1+i)%7, (sum2*10+i)%7, lim && i == up);
        ans.cnt = (ans.cnt + tmp.cnt)%MOD;
        ans.sum = (ans.sum + (i*m[pos]%MOD*tmp.cnt%MOD + tmp.sum)%MOD)%MOD;
        ans.sqr = (ans.sqr + (i*m[pos]%MOD*2%MOD*tmp.sum%MOD+tmp.sqr)%MOD)%MOD;
        ans.sqr = (ans.sqr + (i*m[pos]%MOD)*(i*m[pos]%MOD)%MOD*tmp.cnt)%MOD;
    }
    if (!lim) F[pos][sum1][sum2] = ans;
    return ans;
}

int Solve(int x)
{
    int p = 0;
    while(x)
    {
        dig[p++] = x%10;
        x /= 10;
    }
    return dfs(p-1, 0, 0, 1).sqr;
}

void work()
{
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", ((Solve(b)-Solve(a-1))%MOD+MOD)%MOD);
    return;
}

signed main()
{
    m[0] = 1; for (int i = 1;i < 20;i++) m[i] = m[i-1]*10;
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
