#include <bits/stdc++.h>
// #define int long long

using namespace std;

const int MAXN = 1e3 + 3;

int n;
int a[MAXN][MAXN];
int r[MAXN], c[MAXN], h[MAXN], l[MAXN], hf1[MAXN], lf1[MAXN];

signed main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
            {
                h[i]++;
                l[j]++;
            }
            if (a[i][j] == -1)
            {
                hf1[i]++;
                lf1[j]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &r[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &c[i]);
    }
    queue<pair<int, int>> q;
    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (a[i][j] == -1)
            {
                if (hf1[i] == 1)
                {
                    if (r[i] == 1)
                    {
                        if (h[i] % 2 == 0)
                        {
                            a[i][j] = 1;
                            h[i]++;
                            l[j]++;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                        else
                        {
                            a[i][j] = 0;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                    }
                    else
                    {
                        if (h[i] % 2 == 0)
                        {
                            a[i][j] = 0;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                        else
                        {
                            a[i][j] = 1;
                            h[i]++;
                            l[j]++;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                    }
                }
                else if (lf1[j] == 1)
                { //
                    if (c[i] == 1)
                    {
                        if (l[i] % 2 == 0)
                        {
                            a[i][j] = 1;
                            h[i]++;
                            l[j]++;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                        else
                        {
                            a[i][j] = 0;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                    }
                    else
                    {
                        if (l[i] % 2 == 0)
                        {
                            a[i][j] = 0;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                        else
                        {
                            a[i][j] = 1;
                            h[i]++;
                            l[j]++;
                            hf1[i]--;
                            lf1[j]--;
                            continue;
                        }
                    }
                }
                else
                {
                    q.push(make_pair(i, j));
                }
            }
        }
    }
    // if(!q.empty()) {
    //     printf("-1\n");
    //     return 0;
    // }

    map<pair<int, int>, int> mp;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        if (a[i][j] == -1)
        {
            if (hf1[i] == 1)
            {
                if (r[i] == 1)
                {
                    if (h[i] % 2 == 0)
                    {
                        a[i][j] = 1;
                        h[i]++;
                        l[j]++;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                    else
                    {
                        a[i][j] = 0;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                }
                else
                {
                    if (h[i] % 2 == 0)
                    {
                        a[i][j] = 0;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                    else
                    {
                        a[i][j] = 1;
                        h[i]++;
                        l[j]++;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                }
            }
            else if (lf1[j] == 1)
            { //
                if (c[i] == 1)
                {
                    if (l[i] % 2 == 0)
                    {
                        a[i][j] = 1;
                        h[i]++;
                        l[j]++;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                    else
                    {
                        a[i][j] = 0;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                }
                else
                {
                    if (l[i] % 2 == 0)
                    {
                        a[i][j] = 0;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                    else
                    {
                        a[i][j] = 1;
                        h[i]++;
                        l[j]++;
                        hf1[i]--;
                        lf1[j]--;
                        continue;
                    }
                }
            }
            else
            {
                q.push(make_pair(i, j));
                if (mp[make_pair(i, j)] >= 3)
                {
                    printf("-1");
                    return 0;
                }
                else
                {
                    mp[make_pair(i, j)]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d%c", a[i][j], " \n"[j == n]);
        }
        // printf("\n");
    }
    return 0;
}