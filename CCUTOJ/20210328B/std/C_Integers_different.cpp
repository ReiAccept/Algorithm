/**
 * @author  Moe_Sakiya      i@tun.moe
 * @date        2018-07-26 00:13:41
 *
 */
 
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
const int maxN = 200010;
 
struct Query
{
    int l, r, id;
    bool operator < (const Query & a) const {
        return this->l < a.l;
    }
} q[maxN];
 
int n, m;
int arr[maxN];
int bit[maxN];
int pre[maxN];
int last[maxN];
int nxt[maxN];
int ans[maxN];
bool vis[maxN];
 
int lowBit(int x) {
    return x & -x;
}
 
void update(int x, int y) {
    for (int i = x; i < maxN; i += lowBit(i))
        bit[i] += y;
    return;
}
 
int query(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowBit(i))
        ret += bit[i];
    return ret;
}
 
int main(void) {
    ios::sync_with_stdio(false);
    int l, r, tmp;
    cin.tie(NULL);
    while (~scanf("%d %d", &n, &m)) {
        memset(vis, 0, sizeof(vis));
        memset(bit, 0, sizeof(bit));
        memset(nxt, -1, sizeof(nxt));
        memset(last, -1, sizeof(last));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &tmp);
            arr[i + n] = arr[i] = tmp;
        }
        n *= 2;
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[arr[i]] == false) {
                vis[arr[i]] = true;
                pre[i] = pre[i - 1] + 1;
            } else
                pre[i] = pre[i - 1];
            if (~last[arr[i]])
                nxt[last[arr[i]]] = i;
            last[arr[i]] = i;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &l, &r);
            q[i].l = r;
            q[i].r = l + n / 2;
            q[i].id = i;
        }
        sort(q, q + m);
        int nowL = 1;
        for (int i = 0; i < m; i++) {
            while (nowL < q[i].l) {
                if (~nxt[nowL])
                    update(nxt[nowL], 1);
                nowL++;
            }
            ans[q[i].id] = pre[q[i].r] - pre[q[i].l - 1] + query(q[i].r) - query(q[i].l - 1);
        }
        for (int i = 0; i < m; i++)
            printf("%d\n", ans[i] );
    }
    return 0;
}