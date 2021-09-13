#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
ll a[53],b[53];

void Solve()
{
    n=qrd();
    ll minn1=1e15,minn2=1e15;
    for(int i=1;i<=n;i++)
    {
        a[i]=qrd();
        minn1=min(minn1,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=qrd();
        minn2=min(minn2,b[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++) ans+=max(a[i]-minn1,b[i]-minn2);
    cout<<ans<<endl;
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
