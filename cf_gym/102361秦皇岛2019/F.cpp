#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=3e5+3;
const int MOD=998244353;

int n,m,cnt;
int d[MAXN],dfa[MAXN];
vector<int> grap[MAXN];

int qpow(int a,int b,int mod) {
    int ans=1;
    while(b) {
        if(b&1) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans%mod;
}

void dfs(int now,int p)
{
    dfa[now]=dfa[p]+1;
    for(auto v: grap[now]) {
        if(v==p) continue;
        if(dfa[v]!=0) {
            if(dfa[v] < dfa[now]) {
                d[++cnt]=dfa[now]-dfa[v]+1;
            }
        } else {
            dfs(v,now);
        }
    }
}

signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int u,v,i=1;i<=m;i++) {
        scanf("%lld%lld",&u,&v);
        grap[u].push_back(v);
        grap[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        if(d[i]==0) {
            dfs(i,0);
        }
    }
    for(int i=1;i<=cnt;i++) {
        m-=d[i];
    }
    int ans=qpow(2,m,MOD);
    for(int i=1;i<=cnt;i++) {
        int num=(qpow(2,d[i],MOD)-1+MOD)%MOD;
        ans=(ans*num)%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
