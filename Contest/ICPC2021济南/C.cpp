#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MOD=998244353;
const int INF=0x3f3f3f3f;
const int MAXN=1e6+3;

int n;
int a[MAXN],sum[MAXN];

void work() {
    n=read(); a[n+1]=-INF;
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    sort(a+1,a+1+n,[](int a,int b){
        return a>b;
    });
    // for(int i=n;i>=1;i--) {
    //     if(a[i]!=a[i+1]) sum[i]=1;
    //     else sum[i]=sum[i+1]+1;
    // }
    // for(int i=1;i<=n;i++) {
    //     if(a[i]==a[i-1]) {
    //         sum[i]=sum[i-1];
    //     }
    // }
    // for(int i=1;i<=n;i++) {
    //     printf("%lld%c",a[i]," \n"[i==n]);
    // }
    // for(int i=1;i<=n;i++) {
    //     printf("%lld%c",sum[i]," \n"[i==n]);
    // }
    // int ans=1;
    // for(int i=1;i<=n;i+=1) {
    //     ans=(ans*sum[i])%MOD;
    // }
    // printf("%lld\n",ans);
    return;
}

signed main() {
    work();
    return 0;
}