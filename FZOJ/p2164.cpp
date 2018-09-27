#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int x,y,v;
}Edge[10003];

int n,m,k,ans;
int fa[1003];

int findx(int x)
{
    if(fa[x]!=x)
        fa[x]=findx(fa[x]);
    return fa[x];
}

bool cmp(Node a,Node b)
{
    return a.v<b.v;
}

inline void mixx(int x,int y,int i)
{
    fa[x]=y;
    ans+=Edge[i].v;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    if(n==k)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(n<k)
    {
        cout<<"No Answer"<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
        cin>>Edge[i].x>>Edge[i].y>>Edge[i].v;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(&Edge[1],&Edge[m],cmp);
    for(int i=1;i<=m;i++)
    {
        int fx=findx(Edge[i].x),fy=findx(Edge[i].y);
        if(fx!=fy)
        {
            mixx(fx,fy,i);
            n--;
            if(n<=k)
            {
                cout<<ans<<endl;
                return 0;
            }
        } 
    }
    cout<<"No Answer"<<endl;
    return 0;
}
