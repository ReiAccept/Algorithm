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

void exgcd(ll a, ll b, ll &d, ll &x, ll &y){ //Start EXGCD Tamplate
    if(!b){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        exgcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}//END EXGCD Tamplate

void work(int a,int b)
{
    int x,y,d;
    exgcd(a,b,d,x,y);
    if(d>1) cout<<"sorry"<<endl;
    else
    {
        x=((x%b)+b)%b;
        cout<<x<<" "<<(1-a*x)/b<<endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        int a, b;
        //printf("Case %d: ",Case);
        while(cin>>a>>b) work(a,b);
    }
    return 0;
}
