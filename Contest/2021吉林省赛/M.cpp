#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e4+3;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,minn=INF,maxx=-INF;
int a[MAXN];

signed main() {
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &a[i]);
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
    }
    printf("%lld",n*(maxx-minn));
    return 0;
}