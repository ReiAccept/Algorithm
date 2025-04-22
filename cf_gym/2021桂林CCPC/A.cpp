#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

int x;

void work() {
    x=read();
    printf("%lld\n",(x-1)*2+1);
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}