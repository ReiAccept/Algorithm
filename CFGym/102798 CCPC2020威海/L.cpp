#include<bits/stdc++.h>

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

const int MAXN=30000+30;
int cnt;
int prime[MAXN];
bool vis[MAXN];
double dp[MAXN],logs[MAXN];

void work() {
    int n=read();
    printf("%.9lf\n",dp[n]);
}

signed main() {
    for(int i=2;i<=MAXN;i++) {
        if(!vis[i]) prime[cnt++]=i;
        for(int j=0;prime[j]<=MAXN/i;j++) {
            vis[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
    
    for(int i=1;i<=MAXN;i++) {
        logs[i]=log(i);
    }

    for(int i=0;i<cnt;i++) {
        for(int j=MAXN-1;j>=prime[i];j--) {
            for(int k=prime[i];k<=j;k*=prime[i]) {
                dp[j]=max(dp[j],dp[j-k]+logs[k]);
            }
        }
    }

    signed T; scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}