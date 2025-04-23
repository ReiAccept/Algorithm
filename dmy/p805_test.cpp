#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 100005;
const int MAXM = 1000005;

struct Edge{
    int u, v, c;
    bool operator<(const Edge &other) {
        return c < other.c;
    }
} edge[MAXM];

int n, m, q;
int p[MAXN];
int ans[MAXM];
vector<pair<int,int>>G[MAXN];
int son[MAXN], siz[MAXN], top[MAXN], pre[MAXN], dep[MAXN], val[MAXN], pos[MAXN], dfs_clock;
int preMaxv[MAXN];
int maxv[MAXN<<1];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

inline int getIdx(int l, int r) {
    return l + r | l != r;
}

void dfs(int u, int f) {
    siz[u] = 1;
    son[u] = 0;
    for(const auto &[v, id] : G[u]) {
        if(v == f) {
            continue;
        }
        pre[v] = u;
        dep[v] = dep[u] + 1;
        val[v] = edge[id].c;
        dfs(v, u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}

void rebuild(int u, int top_element) {
    top[u] = top_element;
    pos[u] = ++dfs_clock;
    maxv[getIdx(pos[u], pos[u])] = val[u]; // for seg tree
    if(son[u]) {
        preMaxv[son[u]] = max(preMaxv[u], val[son[u]]);
        rebuild(son[u], top_element);
    }
    for(const auto &[v, _] : G[u]) {
        if(v != pre[u] && v != son[u]) {
            preMaxv[v] = val[v];
            rebuild(v, v);
        }
    }
}

int build(int l, int r) {
    if (l == r) {
        return maxv[getIdx(l, r)];
    }
    int mid = (l + r) / 2;
    return maxv[getIdx(l, r)] = max(build(l, mid), build(mid+1, r));
}

int query(int l, int r, int L, int R) {
    if(L <= l && r <= R) return maxv[getIdx(l, r)];
    int mid = (l + r) / 2;
    if(R <= mid) return query(l, mid, L, R);
    if(mid < L) return query(mid+1, r, L, R);
    return max(query(l, mid, L, R), query(mid+1, r, L, R));
}

int lca(int x, int y) {
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = max(ans, preMaxv[x]);
        x = pre[top[x]];
    }
    if(x == y) {
        return ans;
    }
    if(dep[x] > dep[y]) swap(x, y);
    ans = max(ans, query(1, n, pos[son[x]], pos[y]));
    return ans;
}

void read(int &n, char c = 0) {
    while((c = getchar()) < '0');
    n = c - '0';
    while((c = getchar()) >= '0' && c <= '9') n = (n<<3) + (n<<1) + c - '0';
}

void solve () {
    int u, v, pu, pv;
    read(n);
    read(m);
    //scanf("%d%d", &n, &m);
    dfs_clock = 0;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        G[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        read(edge[i].u);
        read(edge[i].v);
        read(edge[i].c);
        //scanf("%d%d%d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }
    sort(edge + 1, edge + m + 1);
    for(int i = 1; i <= m; i++) {
        u = edge[i].u;
        v = edge[i].v;
        pu = find(u);
        pv = find(v);
        if(pu != pv) {
            p[pu] = pv;
            G[u].emplace_back(v, i);
            G[v].emplace_back(u, i);
        }
    }
    preMaxv[1] = 0;
    dfs(1, 1);
    rebuild(1, 1);
    build(1, n);
    read(q);
    //scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        read(u);
        read(v);
        //scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}

int main() {
    int T = 1;
    // scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        // printf("Case #%d: ", i);
        solve();
    }
    return 0;
}