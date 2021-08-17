#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long n,m,res,a[200003];
long long ans;

bool cmp(long long x,long long y)
{
    return x>y;
}

int main()
{
    cin>>n>>m;
    for(long long i=1;i<=m;i++)
    {
        long long l,r;
        cin>>l>>r;
        ++a[l];--a[r+1];
    }
    for(long long i=1;i<=n;i++) a[i]+=a[i-1];
    long long nx=n;
    sort(a+1,a+1+n,cmp);
    for(long long i=1;i<=n;i++)
    {
        if(a[i]==0) break;
        ans+=(a[i]*nx--);
    }
    cout<<ans<<endl;
    return 0;
}


