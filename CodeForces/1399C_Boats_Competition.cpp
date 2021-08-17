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

int n,ans;
int a[53];//桶排大法好

void work()
{
    mmst0(a);ans=0;
    scanf("%lld",&n);
    for(int tmp,i=1;i<=n;i++)
    {
        scanf("%lld",&tmp);
        a[tmp]++;
    }
    for(int i=2;i<=100;i++)//50+50=100
    {
        int tmp=0;
        for(int j=i-50>1?i-50:1;j<=50;j++)
            if(i-j<0 || j>i-j) break;
            else if(j==i-j)tmp+=(a[j]>>1);
            else tmp+=min(a[j],a[i-j]);
        if(tmp>ans)ans=tmp;
    }
    printf("%lld\n",ans);
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
