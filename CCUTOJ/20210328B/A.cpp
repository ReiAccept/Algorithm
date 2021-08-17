#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int mod=1000000007;
 
int n,k,l,r;
int sum[100003];
int f[100003][2]={1};
 
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=100000;i++)
    {
        f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
        if(i>=k) f[i][1]=f[i-k][0]%mod;
        sum[i]=(sum[i-1]+f[i][1]+f[i][0])%mod;
    }
    while(n--)
    {
        cin>>l>>r;
        cout<<(sum[r]-sum[l-1]+mod)%mod<<endl;
    }
    return 0;
}
