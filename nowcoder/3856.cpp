#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef long double real;

const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
int n,m;
const int MOD=100000;

int g[103][103];
int fa[103];

void work()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        fa[i]=i;
        for(int j=0;j<n;j++) g[i][j]=-1;
        g[i][i]=0;
    }
    for(int u,v,i=0;i<n;i++)
    {
        scanf("%lld%lld",&u,&v);

    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read(T);
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
