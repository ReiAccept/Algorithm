#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+3, mod=1e9+7;
int f[N], fact[N], infact[N];
int n,k;

int qpow(int a,int b){
    int ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return  ans%mod;
}
void init()
{
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++) {
        fact[i]=fact[i-1]*i%mod;
        infact[i]=infact[i-1]*qpow(i,mod-2)%mod;
    }
}
// void init2()
// {
//     f[0]=1;
//     for(int i=1;i<=N;i++) {
//         f[i]=f[i-1]*(4*i-2)/(n+1);
//     }
//     for(int i=1;i<=16;i++) {
//         cout<<f[i]<<" ";
//     }
//     cout<<endl;
// }
int solve(int n)
{
    return fact[2*n]*infact[n]%mod*infact[n]%mod*infact[n+1]%mod;
}

signed main()
{
    init();
    // init2();
    for(int i=1;i<22;i++) {
        cout<<solve(i)<<" ";
    }
    cout<<endl;
    cin>>n>>k;
    //cout<<infact[n+1]<<" "<<fact[2*n]<<" "<<infact[n]<<" "<<qpow(n,k)<<endl;
    // cout<<infact[n+1]%mod*fact[2*n]%mod*infact[n]%mod*infact[n]%mod*qpow(k,n)%mod<<endl;
    // cout<<qpow(n+1,mod-2)%mod*fact[2*n]%mod*qpow(n,mod-2)%mod*qpow(n,mod-2)%mod*qpow(k,n)%mod<<endl;
    cout<<f[24]%mod * qpow(k,n)%mod<<endl;
    return 0;
}