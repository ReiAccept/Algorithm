#include<bits/stdc++.h>
// #define int long long

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

const int MAXN=1e3+5;

int n,cnt;
vector<int> G[MAXN];
int d[MAXN];

void dfs(int cur,int lst) {
    d[cur]=cnt++;
    for(auto x : G[cur]) {
        if(x!=lst)
            dfs(x,cur);
    }
    cnt++;
}

void work() {
    n=read(); d[0]=-1; cnt=0;
    for(int i=0;i<=MAXN;i++) {
        G[i].clear();
        d[i]=0;
    }
    for(int u,v,i=1;i<=n-1;i++) {
        u=read(); v=read();
        // if(u>v) swap(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // for(int i=1;i<=n;i++) {
    //     sort(G[i].begin(),G[i].end());
    // }
    dfs(1,0);
    double sum=0;
    for(int i=1;i<=n;i++) {
        sum+=d[i];
    }
    printf("%.10lf\n",sum/(double)(n-1));
    // printf("DBG(d_i): ");
    // for(int i=1;i<=n;i++) {
    //     printf("%lld%c",d[i]," \n"[i==n]);
    // }
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    } 
    return 0;
}