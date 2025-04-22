#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e5+3;

int n,m,ans;
int w[MAXN];

priority_queue<int,vector<int>,greater<int> > q;

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int w,i=1;i<=n;i++) {
        scanf("%lld",&w);
        if(i<=m) {
            q.push(w);
        } else {
            q.push(q.top()+w);
            q.pop();
        }
    }
    while(!q.empty()) {
        ans=max(ans,q.top());
        q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}