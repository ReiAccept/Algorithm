#include<cstdio>
#include<iostream>

using namespace std;

int Case,n,m,i,x,y,ed;
int g[100010],v[200010],nxt[200010],a[100010];
bool ans[200010];

void add(int x,int y)
{
    v[++ed]=y;
    nxt[ed]=g[x];
    g[x]=ed;
}

void dfs(int x,int y,int z)
{
    z+=a[x];
    ans[z]=1;
    for(int i=g[x]; i; i=nxt[i])
        if(v[i]!=y)
            dfs(v[i],x,z);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>Case;
    while(Case--)
    {
        cin>>n>>m;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            g[i]=0;
        }
        ed=0;
        for(i=1; i<n; i++)
        {
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }
        for(i=0; i<=n+n; i++)
            ans[i]=0;
        for(i=1; i<=n; i++)
            dfs(i,0,0);
        while(m--)
        {
            cin>>x;
            if(ans[x])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}
