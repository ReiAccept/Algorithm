#include <bits/stdc++.h>
#define int long long
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

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}

int n,k;
int a[100003];

void work()
{
    n=read();k=read()-1;
    if (n <= 61 && (int)1<<(n-1) <=k)
    {
        printf("-1\n");
        return;
    }
    iota(a+1, a+n+1, 1);
    for(int i=60,j;i>=0;i=j)
    {
        j = i-1;
        if (~(k>>i)&((int)1)) continue;
        while (j >= 0 && ((k>>j)&1))j--;
        reverse(a+n-1-i, a+n-j);
    }
    for(int i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
    return;
}

signed main()
{
    int T=read();
    while(T--)work();
    return 0;
}

