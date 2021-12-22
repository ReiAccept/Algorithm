#include<bits/stdc++.h>

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

void work() {
    int n=read();
    if(n<=5) {
        printf("-1\n");
    } else if(n%2==0) {
        printf("%d %d\n",2,n-2);
    } else {
        printf("%d %d\n",3,n-3);
    }
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}