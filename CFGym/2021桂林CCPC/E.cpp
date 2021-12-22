#include<bits/stdc++.h>
#define int long long
#define mkp make_pair

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e4+3;
int n,m,c;
bool flag=true;
int d[MAXN];
bool vis[MAXN];

vector<pair<int,int> > E[MAXN];

bool dij(int start) {
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int> > q; //以 first 排序，所以把去向的 v 塞到第二位
    d[start]=0;
    q.push(mkp(0,start));
    while(!q.empty()) {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto x:E[u]) {
            int v=x.first,dis=x.second;
            if(v==start) {
                if(d[u]+dis <=c) {
                    return true; //有环 , 返回 true (这段仅对 2021 的 CCPC 桂林 E 题，找是否存在权小于 c 的环)
                }
            }
            if(vis[v]==false && d[v]>d[u]+dis) { //当前路径长度小于之前路径，更新最短路
                d[v]=d[u]+dis;
                q.push(mkp(-d[v],v)); //往里面塞负的就可以当成反向的优先队列
            }
        }
    }
    return false;
}

void work() {
    n=read(); m=read(); c=read();
    for(int u,v,p,i=1;i<=m;i++) {
        u=read(); v=read(); p=read();
        E[u].push_back(mkp(v,p));
        if(p<=c) {
            flag=false;
        }
    }
    if(flag) {
        printf("0\n");
        return;
    }
    for(int i=1;i<=n;i++) {
        if(dij(i)) {
            printf("2\n");
            return;
        }
    }
    printf("1\n");
    return;
}

signed main() {
    int T=1;//read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}