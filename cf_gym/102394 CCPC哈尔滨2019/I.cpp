#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e5+3;
const int MOD=1e9+7;
const int INF=1e18;

int n,ans,cnt;
int h[MAXN];
bool flag;

void work() {
    n=read(); flag=false; ans=1; cnt=0;
    for(int i=1;i<=n;i++) {
        h[i]=read();
        if(h[i]<h[i-1] || h[i]>=n) {
            flag=true;
        }
    }
    if(flag || h[1]!=0) {
        printf("0\n");
        return;
    }
    for(int i=2;i<=n;i++) {
        if(h[i]==h[i-1]) { //这个位置插入的不是最大值或者最小值
            // ans=ans*cnt%MOD;
            // cnt--;
            ans=ans*(h[i]+2-i)%MOD;
        } else if(h[i]>h[i-1]) { //这个位置插入的 a_i 是最大值或者最小值
            ans=ans*2%MOD;
        }
        // cnt--;
    }
    printf("%lld\n",ans);
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}