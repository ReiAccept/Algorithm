// 很显然这份代码不是我写的 , 写完主席树版本之后找来的 AC 代码学习离线做法
#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
const int maxn = 1e5 + 5;
#define P pair<int,int>
int n,m,s[maxn],res[maxn];
P a[maxn];
struct node{
    int l,r,x,id;
    friend bool operator < (const node a,const node b){
        return a.x < b.x;
    }
}ask[maxn];
int lowbit(int x){
    return -x & x;
}
void update(int x){
    for(int i = x; i <= n; i += lowbit(i)) {
        s[i] ++;
    }
}
int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) {
        res += s[i];
    }
    return res;
}
void solve(){
    cin >> n >> m;
    memset(s,0,4 * (n + 1));
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= m; ++i) {
        cin >> ask[i].l >> ask[i].r >> ask[i].x;
        ask[i].id = i;
    }
    sort(ask + 1,ask + 1 + m);
    int r = 1;
    for(int i = 1; i <= m; ++i) {
        while (a[r].first <= ask[i].x && r <= n){
            update(a[r++].second);
        }
        res[ask[i].id] = query(ask[i].r) - query(ask[i].l - 1);
    }
    for(int i = 1; i <= m; ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();

}