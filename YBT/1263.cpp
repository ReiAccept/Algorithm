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

struct city
{
    int x,y;
    bool operator < (city &b)
    {
        if(x==b.x)return y<b.y;
        return x<b.x;
    }
}c[5003];

int n,ans;
int f[5003];

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        c[i].x=read();
        c[i].y=read();
    }
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)f[i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
            if(c[i].y>c[j].y && f[j]+1>f[i]) f[i]=f[j]+1;
        if(f[i]>ans)ans=f[i];
    }
    printf("%lld\n",ans);
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
