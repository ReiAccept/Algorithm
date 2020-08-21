#include<bits/stdc++.h>

using namespace std;

int n,m;
queue<int> q;
vector<int> g[100003];
bool vis[100003];

void dfs(int now,int deep)
{
    cout<<now<<" ";
    vis[now]=true;
    if(deep==n) return;
    for(unsigned i=0;i<g[now].size();i++) if(!vis[g[now][i]]) dfs(g[now][i],deep+1);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
    dfs(1,1);
    cout<<endl;
    memset(vis,0,sizeof(vis));
    q.push(1);
    vis[1]=true;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(unsigned i=0;i<g[now].size();i++) if(!vis[g[now][i]])q.push(g[now][i]),vis[g[now][i]]=true;
        cout<<now<<" ";
    }
    return 0;
}
