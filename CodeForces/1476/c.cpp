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

int n,now,ans;
int a[200003],b[200003],c[200003];

void work()
{
    n=read(),ans=0;
    for(int i=1; i<=n; i++) c[i]=read()-1;
    for(int i=0; i<n; i++) a[i]=read();
    for(int i=0; i<n; i++) b[i]=read();
    now=abs(a[1]-b[1])+c[2]+2;
    for(int i=2; i<n; i++)
    {
        ans=max(ans,now);
        if(a[i]!=b[i]) now=max(now-abs(a[i]-b[i]),abs(a[i]-b[i]))+2+c[i+1];
        else now=2+c[i+1];
    }
    cout<<max(ans,now)<<endl;
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
