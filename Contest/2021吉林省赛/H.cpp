#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=3e5+3;
const int INF=0x3f3f3f3f3f3f3f3f;
const int MOD=998244853; 

int n,m,k;
int a[MAXN];

vector<pair<int,int> > grap[MAXN];

// pair<int,int> t[MAXN];

int qpow(int a,int b,int mod) {
    int res=1;
    while(b) {
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

// int fact[MAXN];
// int infact[MAXN];

// int ny(int a,int b) {
//     return fact[a]*infact[b]%MOD * infact[a-b]%MOD;
// }
int ans;

// unordered_map<pair<int,int> ,int > mp;
map<pair<int,int> ,int > mp;

void bfs() {
    queue<int> q;
    for(int i=1;i<=k;i++) {
        q.push(a[i]);
    }
    int road_i=k;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        road_i--;
        if(q.empty()) {
            return;
        }
        if(mp.count(make_pair(u,q.front()))) {
            ans=(ans+mp[make_pair(u,q.front())]*qpow(10,road_i-1,MOD)%MOD)%MOD;
            continue;
        }
        bool flag=true; //到不了
        int mother=0,son=0;
        for(auto p : grap[u]) {
            if(p.first==q.front()) {
                flag=false; //可以到
                mother+=p.second;
                son++;
            }
            // printf("%lld %lld\n",u,p.first);
        }
        if(flag) {
            printf("Stupid Msacywy!");
            exit(0);
        }
        // t[road_i]=make_pair(mother,son);
        int tot=mother*qpow(son,MOD-2,MOD)%MOD;
        mp[make_pair(u,q.front())]=tot;
        tot=(tot*qpow(10,road_i-1,MOD)%MOD)%MOD;
        ans=(ans+tot)%MOD;
    }
}

signed main() {
    // fact[0]=infact[0]=1;
    // for(int i=1;i<MAXN;i++) {
    //     fact[i]=fact[i-1]*i%MOD;
    //     infact[i]=infact[i-1]*qpow(i,MOD-2,MOD)%MOD;
    // }
    // printf("%lld\n",(115*qpow(6,MOD-2,MOD)%MOD)%MOD);

    scanf("%lld%lld%lld",&n,&m,&k);
    for(int u,v,w,i=1;i<=m;i++) {
        scanf("%lld%lld%lld",&u,&v,&w);
        grap[u].push_back(make_pair(v,w));
        grap[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=k;i++) {
        scanf("%lld",&a[i]);
    }
    bfs();
    printf("%lld",ans%MOD);
    return 0;
}