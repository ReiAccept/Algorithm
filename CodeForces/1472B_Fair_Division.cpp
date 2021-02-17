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

int n;

void work()
{
    int one=0,two=0;
    scanf("%lld",&n);
    for(int tmp,i=1; i<=n; i++)
    {
        scanf("%lld",&tmp);
        if(tmp==1) one++;
        else two++;
    }
    if(two%2==0)
    {
        if(one%2==0) printf("YES\n");
        else printf("NO\n");
    }
    else
    {
        one-=2;
        if(one<0)printf("No\n");
        else if(one%2==0) printf("YES\n");
        else printf("NO\n");
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;
    scanf("%lld",&T);
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
