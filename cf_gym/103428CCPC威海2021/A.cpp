#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e6+3;

int n,cnt,ans;

int deg[MAXN];

signed main() {
    scanf("%lld",&n);
    for(int u,v,i=1;i<n;i++) {
        scanf("%lld%lld",&u,&v);
        deg[u]++; deg[v]++;
    }
    for(int i=1;i<=n;i++) {
        if(deg[i] <=2 && deg[i] >=1) {
            ans++;
        }
        if(deg[i]>=4) {
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

// bool vis[MAXN];
// vector<int> G[MAXN];

// void dfs(int u) {
//     vis[u]=true;
//     cnt++;
//     for(auto v:G[u]) {
//         if(!vis[v]) {
//             dfs(v);
//         }
//     }
//     return;
// }

// signed main() {
//     scanf("%lld",&n);
//     for(int u,v,i=1;i<n;i++) {
//         scanf("%lld%lld",&u,&v);
//         G[u].push_back(v);
//         G[v].push_back(u);
//     }
//     for(int i=1;i<=n;i++) {
//         // printf("G_%lld SIZ: %lld\n",i,G[i].size());
//         if(G[i].size()>=4) {
//             printf("0\n");
//             return 0;
//         }
//     }
//     for(int i=1;i<=n;i++) {
//         if(!vis[i]) {
//             cnt=0;
//             dfs(i);
//             ans=max(ans,cnt-1);
//         }
//     }
//     printf("%lld\n",ans);
//     return 0;
// }