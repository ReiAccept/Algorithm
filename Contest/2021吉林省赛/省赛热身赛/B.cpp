#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MOD=1e9+7;
const int N=1e3+5;

int n,m;

// int cal(int n,int r) {
//     int sum=1;
//     for(int i=1;i<=r;i++) {
//         sum=(sum*(n+1-i)/i)%MOD;
//     }
//     return sum%MOD;
// }

int fact[N],infact[N];
int qpow(int a,int b,int mod) {
    int res=1;
    while(b) {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

signed main() {
    cin>>n>>m;
    fact[0]=infact[0]=1;
    for(int i=1;i<N;++i) {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=infact[i-1]*qpow(i,MOD-2,MOD)%MOD;
    }
    int ans=fact[n]*infact[m]%MOD*infact[n-m]%MOD;
    cout<<ans<<endl;
    return 0;
}