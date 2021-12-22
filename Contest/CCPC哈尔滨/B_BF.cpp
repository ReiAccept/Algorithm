#include<bits/stdc++.h>

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

const int MAXN=2e5+3;
const int INF=0x3f3f3f3f;

int n,cnt;
int a[MAXN];


signed main() {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    int ans=0;
    for(int sumd=1;sumd<=200;sumd++) {
        cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(a[i]+a[j]==sumd) {
                    ans++;
                    break;
                }
            }
        }
        ans=max(ans,cnt);
    }
    // sort(a+1,a+1+n);
    return 0;
}