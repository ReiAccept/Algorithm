#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int t,v;
}Edge[1000003];

int n,ans,sum;
int fa[1000003];

int findx(int x)
{
    if(fa[x]!=x)
        fa[x]=findx(fa[x]);
    return fa[x];
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>Edge[i].t>>Edge[i].v;
        sum+=Edge[i].v;
    }
    for(int i=1;i<=1000003;i++)
        fa[i]=i;
    sort(&Edge[1],&Edge[n+1],[](Node a,Node b){return a.v>b.v;});
    for(int i=1;i<=n;i++)
    {
        int fx=findx(fa[Edge[i].t]);
        if(fx)
        {
            ans+=Edge[i].v;
            fa[fx]=findx(fx-1);
        }
    }
    cout<<sum-ans<<endl;
    return 0;
}
