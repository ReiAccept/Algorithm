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

int n,al,bb;
int a[200003];

void work()
{
    scanf("%lld",&n);al=bb=0;
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+1+n,[](int a,int b){
            return a>b;
            });
    for(int i=1;i<=n;i++)
    {
        if(i%2 && a[i]%2==0)al+=a[i];
        if(i%2==0 && a[i]%2==1)bb+=a[i];
    }
    if(bb>al)printf("Bob\n");
    else if(al>bb)printf("Alice\n");
    else printf("Tie\n");
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
