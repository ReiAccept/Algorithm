#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) push_back(x)

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f3f3f3f3f;

int read()
{
    char c;
    int num,f=1;
    while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
    num=(int)(c-'0');
    while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
    return num*f;
}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));} //警告,如非必须(如__int128),请不要使用快写

int n,m,ans;
int a[103][103],f[103][103];

void work()
{
    mmst0(a);mmst3f(f);
    n=read();m=read();ans=INF;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) a[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int l=1;l<=n;l++)
                for(int r=1;r<=m;r++)
                {
                    if(a[l][r]>=(a[i][j]-i-j+2)+l+r-2) f[l][r]=a[l][r]-(a[i][j]-i-j+2)-l-r+2;
                    else f[l][r]=INF;
                }
            for(int l=1;l<=n;l++)
                for(int r=1;r<=m;r++)
                {
                    if(l+r!=2) f[l][r]+=min(f[l-1][r],f[l][r-1]);
                    if(f[l][r]>INF) f[l][r]=INF;
                }
            ans=min(ans,f[n][m]);
        }
    cout<<ans<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
