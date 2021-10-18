#include <bits/stdc++.h>
using namespace std;
int read() {
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return f * num;
}
const int N = 2e5 + 1009;
struct node {
	int id, v;
} a[N];
vector<int> ver[N];
int n, vis[N], pre[N], ans[N], maxn[N], nxt[N];
int cmp(const node &a, const node &b) {
	return a.v < b.v;
}
int fid(int x) {
	return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
int dfs(int x) {
	if(ans[x] != 0) return ans[x];
	ans[x] = 1;
	if(nxt[x]) ans[x] += dfs(nxt[x]);
	return ans[x];
}
void work() {
	n = read();
	memset(vis, 0, sizeof(int) * (n + 10));
	memset(ans, 0, sizeof(int) * (n + 10));
	memset(nxt, 0, sizeof(int) * (n + 10));
	for(int i = 1; i <= n; i++) {
		pre[i] = i;
		ver[i].clear();
	}
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		ver[x].push_back(y);
		ver[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		a[i].id = i;
		a[i].v = read();
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++) {
		int x = a[i].id;
		vis[x] = 1;
		for(auto y : ver[x]) if(vis[y]) {
			int fy = fid(y);
			if(x == fy) continue;
			nxt[fy] = x;
			pre[fy] = x;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		printf("%d\n", dfs(i));
	}
}
signed main()
{
	int Case = read();
	while(Case--) work();
	return 0;
}
