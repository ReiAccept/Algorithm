#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+3;

struct Node{
    int v;
} t[N<<2];
int a[N];

void pushup(int rt)
{
    int rx=rt<<1;
    t[rt].v=(t[rx].v^t[rx|1].v);
}

void build(int rt,int l,int r)
{
    if(l==r) t[rt].v=a[l];
    else{
        int m=(l+r)>>1,rx=rt<<1;
        build(rx,l,m); build(rx|1,m+1,r);
        pushup(rt);
    }
}

int query(int rt,int nowl,int nowr,int l,int r)
{
    if(r<nowl || nowr<l) return 0;
    if(l<=nowl && nowr<=r) return t[rt].v;
    int m=(nowl+nowr)>>1,rx=rt<<1;
    return (query(rx,nowl,m,l,r) ^ query(rx|1,m+1,nowr,l,r));
}

signed main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int n,q; scanf("%d%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        for(int l,r,i=1;i<=q;i++)
        {
            scanf("%d%d",&l,&r);
            for(int i=1;i<=(l-r);i++)
            cout<<(query(1,1,n,l,r))<<endl;
        }
    }
    return 0;
}

/*
1
5 3 0
1 2 3 4 5
1 3
2 4
3 5
*/