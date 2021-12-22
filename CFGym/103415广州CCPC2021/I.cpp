#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MOD=998244353;

int n;

int qpow(int a,int b) {
    int ans=1;
    while(b) {
        if(b&1) {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void work() {
    n=read();
    if(n==1 || n==2) {
        printf("%lld\n",n);
        return;
    }
    int ans=3*qpow(2,n-2)%MOD;
    printf("%lld\n",ans);
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}