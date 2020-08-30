#include<bits/stdc++.h>

using namespace std;

int n,k;
long long maxn;
long long sum[1000003];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    for(int i=1;i<=n-k;i++) maxn=max(maxn,sum[i+k]-sum[i]);
    cout<<sum[n-1]-maxn<<endl;
    return 0;
}
