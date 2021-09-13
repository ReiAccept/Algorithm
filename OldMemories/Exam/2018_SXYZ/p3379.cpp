#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n,m,s;
bool vis[500003];
vector<int> g[500000];

int LCA1(int a,int b)//ÂýËÙ
{
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        vis[cur]=true;
        if(cur==s) break;
        for(unsigned int i=0;i<g[cur].size();i++){
            q.push(g[cur][i]);
        }
    }
    queue<int> empty;
    swap(empty, q);
    q.push(b);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(vis[cur]) 
            return cur;
        for(unsigned int i=0;i<g[cur].size();i++)
        {
            q.push(g[cur][i]);
        }
    }
}

int main()
{
    //freopen("3379.in","r",stdin);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA1(a,b));
    }
    return 0;
}
