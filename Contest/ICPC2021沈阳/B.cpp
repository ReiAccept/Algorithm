#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e5+10,MAXM=2e5+10;

int n,m;

struct Node {
    int u,v,w;
}e[MAXM];

int read() {
    int x; scanf("%lld",&x); return x;
}

signed main() {
    n=read(); m=read();
    for(int i=1;i<=m;i++) {
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
    }
    return 0;
}