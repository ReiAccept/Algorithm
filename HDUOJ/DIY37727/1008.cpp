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
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

ll phi(ll n){//欧拉函数模板
	ll ans = n;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0){
			ans = ans / i * (i - 1);
			do n /= i;
			while (n % i == 0);
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}//模板结束

int n,m;

void work()
{
    n=read();m=read();
    int ans=0;
    for(int i=1;i*i<=n;i++)
        if(!(n%i))
        {
            if(i>=m) ans+=phi(n/i);
            if(i*i!=n && n/i>=m) ans+=phi(i);
        }
    cout<<ans<<endl;
    return;
}

signed main()
{
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
