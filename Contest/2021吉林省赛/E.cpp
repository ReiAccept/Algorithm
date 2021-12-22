#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e5+3;
const int INF=0x3f3f3f3f3f3f3f3f;

int n;
int a[MAXN];

void work() {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    // printf("%lld\n",6^5);
    for(int i=2;i<=n;i++) {
        if((a[i]^a[i-1])==1) {
            // printf("%lld %lld\n",a[i],a[i-1]);
            printf("Yes");
            return;
        }
    }
    printf("No");
}

signed main() {
    int T=1; scanf("%lld",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
        if(CASE!=T){
            printf("\n");
        }
    }
    return 0;
}