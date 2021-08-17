#include<bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f,maxn=1e5+40;
int n, m, a[maxn];
pair<int, int> v[maxn], ans[maxn];
set< pair<int, int> > st[maxn * 2];
set< pair<int, int> >::iterator it;

int main(void)
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &v[i].first, &v[i].second), st[v[i].second - v[i].first + maxn].insert(v[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        a[i]+=maxn;
    }
    bool flag=true;
    pair<int, int> maxs(-INF, -INF);
    for (int i = 0; i < n; i++)
    {
        if (st[a[i]].empty())
        {
            flag = false;
            break;
        }
        it = st[a[i]].begin();
        ans[i] = *it;
        st[a[i]].erase(it);
        if (ans[i].first<=maxs.first && ans[i].second<=maxs.second)
        {
            flag = false;
            break;
        }
        maxs = max(maxs, ans[i]);
    }
    if(flag)
    {
        puts("YES");
        for (int i=0;i<n;i++) printf("%d %d\n", ans[i].first, ans[i].second);
    }
    else puts("NO");
    return 0;
}
