#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define lson rt<<1
#define rson rt<<1|1
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://Code//in.txt","r",stdin)
#define IO ios::sync_with_stdio(false),cin.tie(0)

const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

char op[10];
int t, n, q, l, r, x;

struct node {
    int l, r;
    int sum1, sum2;
    int vis, lazy1, lazy2, lazy3;
}segtree[maxn<<2];

void push_up(int rt) {
    segtree[rt].sum1 = (segtree[lson].sum1 + segtree[rson].sum1) % mod;
    segtree[rt].sum2 = (segtree[lson].sum2 + segtree[rson].sum2) % mod;
}

void push_down(int rt) {
    if(!segtree[rt].vis) return;
    int x = segtree[rt].lazy1, y = segtree[rt].lazy2, z = segtree[rt].lazy3;
    segtree[rt].vis = segtree[rt].lazy1 = segtree[rt].lazy2 = 0, segtree[rt].lazy3 = 1;
    segtree[lson].vis = segtree[rson].vis = 1;
    segtree[lson].lazy1 = (1LL * segtree[lson].lazy3 * x % mod + segtree[lson].lazy1) % mod;
    segtree[rson].lazy1 = (1LL * segtree[rson].lazy3 * x % mod + segtree[rson].lazy1) % mod;
    segtree[lson].lazy2 = (1LL * z * segtree[lson].lazy2 % mod + y) % mod;
    segtree[rson].lazy2 = (1LL * z * segtree[rson].lazy2 % mod + y) % mod;
    segtree[lson].sum1 = ((1LL * segtree[lson].sum2 * z % mod * x % mod + 1LL * segtree[lson].sum1 * z % mod) % mod + 1LL * y * (segtree[lson].r - segtree[lson].l + 1) % mod) % mod;
    segtree[rson].sum1 = ((1LL * segtree[rson].sum2 * z % mod * x % mod + 1LL * segtree[rson].sum1 * z % mod) % mod + 1LL * y * (segtree[rson].r - segtree[rson].l + 1) % mod) % mod;
    segtree[lson].sum2 = 1LL * segtree[lson].sum2 * z % mod * z % mod;
    segtree[rson].sum2 = 1LL * segtree[rson].sum2 * z % mod * z % mod;
    segtree[lson].lazy3 = 1LL * segtree[lson].lazy3 * z % mod;
    segtree[rson].lazy3 = 1LL * segtree[rson].lazy3 * z % mod;
}

void build(int rt, int l, int r) {
    segtree[rt].l = l, segtree[rt].r = r;
    segtree[rt].lazy1 = segtree[rt].lazy2 = 0;
    segtree[rt].lazy3 = 1;
    segtree[rt].sum1 = segtree[rt].vis = 0, segtree[rt].sum2 = 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(rt);
}

void update(int rt, int l, int r, int x) {
    if(segtree[rt].l == l && segtree[rt].r == r) {
        segtree[rt].vis = 1;
        segtree[rt].lazy2 = (10LL * segtree[rt].lazy2 + x) % mod;
        segtree[rt].lazy1 = (1LL * segtree[rt].lazy3 * x % mod + segtree[rt].lazy1) % mod;
        segtree[rt].sum1 = (10LL * ((1LL*segtree[rt].sum2 * x % mod + segtree[rt].sum1 % mod) % mod) % mod + x * (r - l + 1)) % mod;
        segtree[rt].sum2 = 100LL * segtree[rt].sum2 % mod;
        segtree[rt].lazy3 = 10LL * segtree[rt].lazy3 % mod;
        return;
    }
    push_down(rt);
    int mid = (segtree[rt].l + segtree[rt].r) >> 1;
    if(r <= mid) update(lson, l, r, x);
    else if(l > mid) update(rson, l, r, x);
    else {
        update(lson, l, mid, x);
        update(rson, mid + 1, r, x);
    }
    push_up(rt);
}

int query(int rt, int l, int r) {
    if(segtree[rt].l == l && segtree[rt].r == r) return segtree[rt].sum1;
    push_down(rt);
    int mid = (segtree[rt].l + segtree[rt].r) >> 1;
    if(r <= mid) return query(lson, l, r);
    else if(l > mid) return query(rson, l, r);
    else return (query(lson, l, mid) + query(rson, mid + 1, r)) % mod;
}

int main() {
#ifndef ONLINE_JUDGE
    FIN;
#endif // ONLINE_JUDGE
    scanf("%d", &t);
    int icase = 0;
    while(t--) {
        scanf("%d%d", &n, &q);
        build(1, 1, n);
        printf("Case %d:\n", ++icase);
        while(q--) {
            scanf("%s%d%d", op, &l, &r);
            if(op[0] == 'w') {
                scanf("%d", &x);
                update(1, l, r, x);
            } else printf("%d\n", query(1, l, r));
        }
    }
    return 0;
}
