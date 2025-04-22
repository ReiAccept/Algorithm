#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e5+3;
const int INF=0x3f3f3f3f;

int n,m,c,minn=INF;
int d[MAXN];
bool vis[MAXN];

struct qnode {
    int v,c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator < (const qnode &r) const {
        return c>r.c;
    }
};

struct Edge {
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};

vector<Edge> E[MAXN];

void add(int u,int v,int w) {
    E[u].push_back(Edge(v,w));
}

bool dij(int n,int sta) {
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) d[i]=INF;
    priority_queue<qnode> que;
    while(!que.empty()) que.pop();
    d[sta]=0;
    que.push(qnode(sta,0));
    qnode tmp;
    while(!que.empty()) {
        int u=que.top().v;
        que.pop();
        if(vis[u]) {
            continue;
        }
        vis[u]=true;
        for(int i=0;i<E[u].size();i++) {
            int v=E[u][i].v,cost = E[u][i].cost;
            if(v==sta) {
                if(d[u]+cost <=c) {
                    return true;
                }
            }
            if(!vis[v] && d[v]>d[u]+cost) {
                d[v]=d[u]+cost;
                que.push(qnode(v,d[v]));
            }
        }
    }
    return false;
}

void work() {
    bool flag=true;
    n=read(); m=read(); c=read();
    for(int u,v,p,i=1;i<=m;i++) {
        u=read();v=read();p=read();
        add(u,v,p);
        if(p<=c) {
            flag=false;
        } 
    }
    if(flag) {
        printf("0\n");
        return;
    }
    for(int i=1;i<=n;i++) {
        if(dij(n,i)) {
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