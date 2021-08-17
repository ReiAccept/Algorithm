#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int qpow(int a,int b,int ans=1)
{
    while(b)
    {
        if(b&1)ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int n,k;

void work()
{
    n=read();k=read();
    if(k==1 || k>=31)
    {
        printf("%lld\n",n);
        return;
    }
    int ans=0;
    for(int i=1;qpow(i,k)<=n;i++)
    {
        int arr=qpow(i,k),brr=min(n,qpow(i+1,k));
        ans+=(brr-arr-1)/i+1;
    }
    printf("%lld\n",ans);
    return;
}

signed main()
{
    int T = read();
	for(int Case=1;Case<=T;Case++)
    {
        printf("Case #%lld: ",Case);
        work();
    }
    return 0;
}
//分块
