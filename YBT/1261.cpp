#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))
#define pb(x) push_back(x)

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
int g[103][103],f[103],mem[103];

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) g[i][j]=read();
    for(int i=0;i<=101;i++) f[i]=INF;//f[i]表示第i个城市到终点的最短距离
    f[n]=0;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(g[i][j] && g[i][j]+f[j]<f[i])
            {
                f[i]=g[i][j]+f[j];
                mem[i]=j;
            }
        }
    }
    printf("minlong=%lld\n",f[1]);
    int city=1;
    while(city)
    {
        printf("%lld ",city);
        city=mem[city];
    }
    return;
}
//没有啥意义的一个题,强行加维度
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
