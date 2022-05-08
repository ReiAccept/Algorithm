#include<bits/stdc++.h>
using namespace std;

#define pir pair <ll, int>
#define MEM(x, b) memset(x, b, sizeof(x))

typedef long long ll;
const int Mod = 1e9 + 7;
const int N = 3e5 + 100;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

vector <pir> G[N << 1];
ll d1[N], d2[N];
bool vis[N];
int n, m;

void init()
{
    for(int i = 1; i <= 3 * n; i++)
        G[i].clear();
    MEM(d1, 0x3f), MEM(d2, 0x3f);
}
void dijkstra(int x, ll *dis)
{
    priority_queue <pir, vector <pir>, greater <pir>> q;
    MEM(vis, 0);
    q.push({ 0ll, x });
    dis[x] = 0;;
    while (!q.empty())
    {
        pir now = q.top();
        q.pop();
        int u = now.second;
        if (vis[u]) continue;
        vis[u] = true;
        for(auto it : G[u])
        {
            int v = it.second;
            ll w = it.first;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({ dis[v], v });
            }
        }
    }
}

int Case;

void work()
{
    scanf("%d %d", &n, &m);
    init();

    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        int k, u;
        ll w;
        scanf("%lld %d", &w, &k);
        cnt++;
        while (k--)
        {
            scanf("%d", &u);
            G[n + cnt].push_back({ w, u });
            G[u].push_back({ 0, n + cnt });
        }
    }

    dijkstra(1, d1), dijkstra(n, d2);
    printf("Case #%d: ", ++Case);
    ll ans = LINF;
    for(int i=1;i<=n;i++)
        ans=min(ans, max(d1[i], d2[i]));
    if (ans == LINF)
        printf("Evil John\n");
    else
    {
        printf("%lld\n", ans);
        vector <int> v;
        for(int i=1;i<=n;i++)
        {
            if (max(d1[i], d2[i]) == ans)
                v.push_back(i);
        }
        for(int i = 0; i < (int)v.size() - 1; i++)
            printf("%d ", v[i]);
        printf("%d\n", v[(int)v.size() - 1]);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        work();
    }
    return 0;
}
