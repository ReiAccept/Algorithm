#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int t,n,ans;
int a[100003],z[100003],f[100003];

int read()
{
    int re=0,ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        re=re*10+ch-'0';
        ch=getchar();
    }
    return re;
}

int main()
{
    t=read();
    while(t--)
    {
        n=read();
        ans=0;
        for(int i=1; i<=n; i++)
        {
            a[i]=read();
            z[i]=max(z[i-1],a[i]);
        }
        f[n]=a[n];
        for(int i=n-1; i>=1; i--) f[i]=min(f[i+1],a[i]);
        //for(int i=1;i<=n;i++) cout<<f[i]<<" ";
        for(int i=2; i<=n-1; i++)
        {
            if(a[i]>z[i-1] && a[i]>f[i+1])
                ans++;
        }
        cout<<ans<<endl;
    }
}
