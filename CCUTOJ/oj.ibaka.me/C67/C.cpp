#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

struct Edge
{
    int to, next;
}edge[maxn];

int n, m, cnt = 1;
int head[maxn],vis[maxn];
stack<int> S;

void add(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

bool dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v] == 1) return false;
        if (vis[v] == 0 && !dfs(v)) return false;
    }
    vis[u] = -1;
    S.push(u);
    return true;
}

bool topsort()
{
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i] && !dfs(i))
            {
                return false;
            }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    if (topsort()) cout << "Yes" << endl;
    /*{
        while (!S.empty()) {
            cout << S.top() << ' ';
            S.pop();
        }
    }*/
    else cout<<"No"<<endl;
}
//HDU1258改的拓扑板子
