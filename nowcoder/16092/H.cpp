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
const int N=(int)1e3+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct mos{
    int h,s,w;
    void rd(){
        h=read();s=read();w=read();
    }
    //bool operator < const(const mos b){
        //return h<b.h;
    //}
} a[N];

int n,h,s,ans=-INF;
int f[N][N];

void work()
{
    n=read();h=read();s=read();
    for(int i=1;i<=n;i++)a[i].rd();
    for(int i=1; i<=n; i++)
    {
        for(int j=h; j>a[i].h; j--)//血
        {
            for(int k=s+h; k>=a[i].s; k--)//血+盾,s+h确保在先扣盾没伤血
            {
                f[j][k]=f[j-a[i].h][k-a[i].s]+a[i].w>f[j][k]?f[j-a[i].h][k-a[i].s]+a[i].w:f[j][k];
            }
        }
    }
    //cout<< *max_element(f,f+(N-1)*(N-1)) <<endl;
    for(int k=0; k<h; k++)ans=f[h-k][s+k]>ans?f[h-k][s+k]:ans;
    cout<<ans<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

