#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e6+3;
const int INF=0x3f3f3f3f;
int n,minn=INF;
int a[MAXN];

int chk(int x) {
     
}

void work() {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
        minn=min(minn,a[i]);
    }
    bool flag=true;
    for(int i=1;i<=n;i++) {
        if(a[i]%minn) {
            flag=false;
            break;
        }
    }
    if(flag) {
        printf("0\n");
        return;
    }
    // sort(a+1,a+1+n);
    int l=0,r=1e13;
    while(l<r) {
        int m=(l+r)>>1;
    }
    return;
}

signed main() {
    work();
    return 0;
}