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

int c,l;
struct Node{
    int a,b;
    void read(){
        scanf("%lld%lld",&a,&b);
    }
    void prt(){
        printf("%lld %lld\n",a,b);
    }
    bool operator < (Node x)
    {
        if(a==x.a)return b>x.b;
        return a>x.a;
    }
}cow[2503],sfp[2503];

void work()
{
    scanf("%lld%lld",&c,&l);
    for(int i=1;i<=c;i++)cow[i].read();
    sort(cow+1,cow+c+1);
    //for(int i=1;i<=c;i++)cow[i].prt();
    for(int i=1;i<=l;i++)sfp[i].read();
    sort(sfp+1,sfp+l+1);
    int ans=0;
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=l;j++)
        {
            if(cow[i].a<=sfp[j].a && sfp[j].a<=cow[i].b && sfp[j].b>0)
			{
			    sfp[j].b--;
			    ans++;
			    break;
            }
        }
    }
    printf("%lld\n",ans);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//scanf("%lld",&T);
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
