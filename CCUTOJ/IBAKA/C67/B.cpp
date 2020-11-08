#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,ans,ji,ou;
int a[100003];
const int mod=1000000007;

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        a[i]+=a[i-1];
        if(a[i]%2)
        {
            ji++;
            ans=(ans+ou+1)%mod;
        }
        else
        {
            ou++;
            ans=(ans+ji)%mod;
        }
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T = 1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
