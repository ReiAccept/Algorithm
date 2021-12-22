#include<bits/stdc++.h>
// #define int long long

using namespace std;

const int MAXN=650000+3;

int n,q;
int a[MAXN];

struct Node {
    int val,hash;
}tr[MAXN<<2];

void pushup(int rt) {
    int rx=rt<<1;
    tr[rt].val=tr[rx].val+tr[rx|1].val;
}

void build(int nowl,int nowr,int rt) {
    if(nowl==nowr) {
        tr[nowl].val=a[rt];
        return;    
    }
    int nowm=(nowl+nowr)>>1,rx=rt<<1;
    build(nowl,nowm,rx); build(nowm+1,nowr,rx|1);
    pushup(rt);
}

void work() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
}

signed main() {
    int T; scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}