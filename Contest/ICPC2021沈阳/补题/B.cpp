#include<bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e5+3,MAXM=2e5+3;

int n,m,ans;
int a[MAXN];
int c[50][2];
bool flag;
bool vis[MAXN];

vector<pair<int,int>> G[MAXN];

void dfs(int u) {
    vis[u]=1;
    for (auto [v,w]: G[u]) {
        if(vis[v]) {
            if (a[v]!=(a[u]^w)) {
                puts("-1");
                exit(0);
            }
        } else {
            a[v]=(a[u]^w);
            for (int j=0;j<30;j++) {
                c[j][(a[v]>>j)&1]++;
            }
            dfs(v);
        }
    }
}

signed main() {
    n=read(); m=read();
    for(int u,v,w,i=1;i<=m;i++) {
        u=read(); v=read(); w=read();
        G[u].pb(mkp(v,w));
        G[v].pb(mkp(u,w));
    }
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i);
            for (int j=0;j<30;j++) {
                ans+=1ll*min(c[j][0]+1,c[j][1])*(1<<j);
                c[j][0]=c[j][1]=0;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}