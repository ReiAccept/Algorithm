#include<bits/stdc++.h>
//#define int long long//__int128
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
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
rld xs,ys,xt,yt;
rld x[1003],y[1003];
vector<rld> ans[1003];

void work()
{
    n=read();m=read();xs=(rld)read();ys=(rld)read();xt=(rld)read();yt=(rld)read();
    for(int i=1;i<=n;i++) x[i]=(rld)read(),y[i]=(rld)read();
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            rld t=x[i]*(y[j]-y[i])+ys*(x[j]-x[i])-(x[j]-x[i])*y[i]-xs*(y[j]-y[i]);
            t/=(y[j]-y[i])*(xt-xs)-(x[j]-x[i])*(yt-ys);
            if(t<0||t>1) continue;
            ans[i].push_back(t);
            ans[j].push_back(t);
        }
    for(int i=1;i<=n;i++) sort(ans[i].begin(),ans[i].end());
    while(m--)
    {
        int h=read(),k=read();
        if((int)ans[h].size()<k) printf("-1\n");
        else printf("%Lf %Lf\n",ans[h][k-1]*(xt-xs)+xs,ans[h][k-1]*(yt-ys)+ys);
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

