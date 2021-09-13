#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long n,m,res,ans;
long long a[200003],b[200003],c[200003];

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
        a[l]++;b[r]++;
    }
    for(long long i=1;i<=n;i++)
    {
        res+=a[i];
        c[i]=res;
        res-=b[i];
    }
    long long nx=n;
    sort(c+1,c+1+n,cmp);
    for(long long i=1;i<=n;i++)
    {
        if(c[i]==0) break;
        ans+=(c[i]*nx--);
    }
    cout<<ans<<endl;
    return 0;
}

