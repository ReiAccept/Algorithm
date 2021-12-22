#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+3;

int n,ji,ou;
int a[MAXN];

signed main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        if(a[i]%2) {
            ji++;
        } else {
            ou++;
        }
    }
    // for(int i=2;i<=n;i++) {
    //     if(a[i]%2==a[i-1]%2) {
    //         printf("Not Good");
    //     }
    // }
    // printf("Good");
    if(abs(ji-ou)<=1) {
        printf("Good");
    } else {
        printf("Not Good");
    }
    return 0;
}