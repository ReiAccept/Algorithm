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

int n,k;

void work()
{
    n=read();k=read(); 
    if(k==1){cout<<n*2-1<<endl;return;}
    if(k==n){cout<<1<<endl;return;}
    int node=0,cs=1,r=n;
    for(;r>=k;r>>=1){
        node+=cs;
        //if(r%2==1)cs--;
        cs<<=1;
        //cout<<node <<" "<<cs<<" "<<r<<endl;
    }
    node+=cs;
    cout<<node<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    //freopen("1011.in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n)
        work();
    }
    return 0;
}
