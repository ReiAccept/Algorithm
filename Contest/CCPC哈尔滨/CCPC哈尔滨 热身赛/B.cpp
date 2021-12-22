#include<bits/stdc++.h>

using namespace std;

int read() {
    int x; scanf("%d", &x); return x;
}

const int MAXN=2e6+3;

int n,leaves;
int p[MAXN],d[MAXN];
vector<int> G[MAXN];

void dfs(int u,int deep) {
    if(G[u].size()==0) {
        d[++leaves]=deep;
        return;
    }
    for(auto v:G[u]) {
        dfs(v,deep+1);
    }
}

void work() {
    n=read(); leaves=0;
    
    for(int i=0;i<=n+1;i++) {
        G[i].clear();
        p[i]=d[i]=0;
    }
    for(int i=1; i<n; i++) {
        p[i]=read();
        G[p[i]].push_back(i+1);
    }
    dfs(1,1);
    int ans=0;
    for(int i=1;i<=leaves; i++) {
        // printf("%d%c",d[i]," \n"[i==leaves]);
        ans^=d[i];
    }
    if(ans==0) {
        printf("Takeru\n");
    } else {
        printf("Meiya\n");
    }
}

signed main() {
    signed T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}