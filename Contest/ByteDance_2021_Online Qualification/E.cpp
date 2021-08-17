#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar(x%10+'0');}

int n,m;
int a[200003];
//gcd(a , b , c) = gcd(a , b-a , c-b)
void work()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int i=n;i>1;i--)a[i]=a[i]-a[i-1];
    int tmp=a[2];
    for(int i=2;i<=n;i++)tmp=__gcd(tmp,a[i]);
    for(int i=1;i<=m;i++)
    {
        int ans=a[1]+read();//b[i];
        if(n==1)cout<<ans<<" ";
        else cout<<__gcd(tmp,ans)<<" ";
    }
    cout<<endl;
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
