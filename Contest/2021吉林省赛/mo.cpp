#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e5+3;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=1e9+7; 

int n,k;


int qpow(int a,int b,int mod) {
    int res=1;
    while(b) {
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

int fact[MAXN];
int infact[MAXN];

int ny(int a,int b) {
    return fact[a]*infact[b]%MOD * infact[a-b]%MOD;
}
int aa(int a,int b) {
    return fact[a]*infact[a-b]%MOD;
}

signed main() {
    fact[0]=infact[0]=1;
    for(int i=1;i<MAXN;i++) {
        fact[i]=fact[i-1]*i%MOD;
        infact[i]=infact[i-1]*qpow(i,MOD-2,MOD)%MOD;
    }
    int ans=(qpow(20,24,MOD)*ny(48,24)%MOD*qpow(25,MOD-2,MOD)%MOD)%MOD%MOD;
    printf("%lld\n",ans);
    return 0;
}