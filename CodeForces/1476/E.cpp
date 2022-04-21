#include <bits/stdc++.h>

using namespace std;

int n, m, k;
queue<int> q;
map<string, int> mp;
vector<vector<int>> adj(n);
vector<int> ind(n, 0);
int main()
{ 
    scanf("%d%d%d", &n, &m, &k);
    
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        mp[str] = i;
    }
    bool ck = false;
    for(int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        int mk;
        cin >> mk;
        mk--;
        bool flag = false;
        if (ck) continue;

        for(int j = 0; j < (1 << k); j++)
        {
            string tmp = str;
            for(int x = 0; x < k; x++) if ((j >> x) & 1) tmp[x] = '_';
            if (mp.count(tmp))
                if (mp[tmp] == mk) flag = true;
                else
                {
                    adj[mk].push_back(mp[tmp]);
                    ind[mp[tmp]]++;
                }
        }
        if (!flag) ck = true;
    }
    if(ck) printf("NO\n");
    else
    {
        vector<int> res;
        for(int i = 0; i < n; i++) if(!ind[i]) q.push(i);
        while(q.size())
        {
            int u=q.front(); q.pop();
            res.push_back(u);
            for(int v : adj[u])
            {
                ind[v]--;
                if (!ind[v]) q.push(v);
            }
        }
        if(res.size()==n)
        {
            printf("YES\n");
            for(int it : res) printf("%d ",it+1);
        }
        else printf("NO\n");
    }
    return 0;
}
