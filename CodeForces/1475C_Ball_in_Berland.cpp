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

int n,m,k,ans;
int a[200003],b[200003],ha[200003],hb[200003];

void work()
{
    mmst0(ha);mmst0(hb);ans=0;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",a+i);
        ha[a[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",b+i);
        hb[b[i]]++;
    }
    for(int i=1;i<=k;i++) ans+=(k-ha[a[i]]-hb[b[i]]+1);
    printf("%lld\n",(ans>>1));
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
