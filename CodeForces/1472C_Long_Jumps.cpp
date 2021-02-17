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

int n,maxn;
int a[200003];
map<int,int> f;

void work()
{
    f.clear();maxn=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    for(int i=1;i<=n;i++)
    {
        if(f[i]+a[i]>f[i+a[i]])f[i+a[i]]=f[i]+a[i];
		maxn=max(maxn,f[i+a[i]]);
    }
    printf("%lld\n",maxn);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;scanf("%lld",&T);
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
