#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e4+3;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=1e9+7; 

int n,k;

int q_mi(int a,int b) {
    int cnt=1;
    while(b) {
        if(b&1) cnt=(cnt*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return cnt;
}

int a,b,m,x0,x;

signed main() {
    scanf("%lld%lld%lld%lld%lld",&a,&b,&m,&x0,&x);
    return 0;
}