#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int MAXN=2e5+5;
int n,k;
int fact[MAXN],infact[MAXN];
int qpow(int a,int b) {
    int cnt=1;
    while(b) {
        if(b&1) cnt=(cnt*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return cnt;
}
void init() {
    fact[0]=infact[0]=1;
    for(int i=1;i<MAXN;i++) {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=infact[i-1]*qpow(i,MOD-2)%MOD;
    }
}
int cc(int a,int b) {
    return fact[a]*infact[b]%MOD*infact[a-b]%MOD;
}
signed main() {
    scanf("%lld %lld",&n,&k);
    init();
    int x1=cc(2*n,n)%MOD;
    int x2=x1*qpow(n+1,MOD-2)%MOD;
    int ans=qpow(k,n)%MOD*x2%MOD;
    printf("%lld",ans%MOD);
    return 0;
}