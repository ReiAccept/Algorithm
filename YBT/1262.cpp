#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))
#define pb(x) push_back(x)

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f,MOD=1e9+7;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));} //警告,如非必须(如__int128),请不要使用快写

int n,x,y,maxn,maxi;
int a[203],f[203],mem[203];
bool g[203][203];

void work()
{
    n=read();
    for(int i=1;i<=n;i++)f[i]=a[i]=read();
    while(cin>>x>>y && x && y) g[x][y]=true;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(g[i][j] && f[j]+a[i]>f[i])
            {
                f[i]=a[i]+f[j];
                mem[i]=j;
            }
        }
        if(f[i]>maxn) maxn=f[i],maxi=i;
    }
    while(maxi)
    {
        printf("%lld",maxi);
        maxi=mem[maxi];
        if(maxi)printf("-");
    }
    printf("\n%lld\n",maxn);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
