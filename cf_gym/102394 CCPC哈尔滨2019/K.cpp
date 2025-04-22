#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e6+3;

int n,k,wsum;
int w[MAXN];
double wx[MAXN];

void work() {
    n=read(); k=read(); wsum=0;
    for(int i=1;i<=n;i++) {
        w[i]=read();
        wsum+=w[i];
    }
    for(int i=1;i<=n;i++) {
        wx[i]=(double)w[i]/(double)wsum;
    }
    for(int i=1;i<=n;i++) {
        printf("%.8lf%c",w[i]+wx[i]*k," \n"[i==n]);
    }
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}