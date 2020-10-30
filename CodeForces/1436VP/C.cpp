#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,x,pos,l,r,hi,lo,ans=1;
int a[1003];
const int mod=1000000007;

void work()
{
    r=n=read();x=read();pos=read();
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(mid<=pos)
        l=mid+1,a[mid]=1;
        else
        r=mid,a[mid]=2;
    }
    for(int i=0;i<n;i++)//标记去重
    {
        if(i==pos) continue;
        if(a[i]==2) hi++;//比pos大的mid数
        else if(a[i]==1) lo++;//比pos小的mid数
    }
    for(int i=x-1;i>=x-lo;i--) ans=(ans*1ll*i)%mod;
    for(int i=n-x;i>=n-x-hi+1;i--) ans=(ans*1ll*i)%mod;
    for(int i=1;i<=n-hi-lo-1;i++) ans=(ans*1ll*i)%mod;
    cout<<ans%mod<<endl;
    return;
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
