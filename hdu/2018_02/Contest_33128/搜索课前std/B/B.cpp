#include<cstdio>
typedef long long ll;
const int N=50;
int Case,n,m,x,y,d[N];
ll g[N];
ll dfs(int x,ll S) //now consider x,must choose S
{
    if(x==n)
        return 1;
    ll t=dfs(x+1,S);
    if(!d[x])
        return S>>x&1?t:t<<1;
    if(!(S>>x&1))
        t+=dfs(x+1,S|g[x]);
    return t;
}
int main()
{
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%d%d",&n,&m);
        for(x=0; x<n; x++)
            g[x]=d[x]=0;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            x--,y--;
            g[x]|=1LL<<y;
            g[y]|=1LL<<x;
            if(x<y)
                d[x]++;
            else
                d[y]++;
        }
        printf("%lld\n",dfs(0,0));
    }
}
/*
如果1号点度数为0，那么显然
否则1号点度数>0，要么1选，要么和1相连的选
*/
