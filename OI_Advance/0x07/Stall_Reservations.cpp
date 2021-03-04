#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef long double real;

const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF

struct Node
{
    int l,r,num;
    bool operator < (const Node &x) const
    {
        if(r==x.r) return l>x.l;
        return r>x.r;
    }
}c[50003];

int n,sum;
int in[50003];//用于存储牛在哪个牛栏的顺序 
priority_queue<Node> q;

void work()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&c[i].l,&c[i].r);
    for(int i=1;i<=n;i++) c[i].num=i;
    sort(c+1,c+1+n,[](Node a,Node b){
        if(a.l==b.l) return a.r<b.r;
        return a.l<b.l;
    });
    for(int i=1;i<=n;i++)
    {
        if((!q.empty()) && c[i].l>q.top().r)
        {
            in[c[i].num]=in[q.top().num];//牛栏续上 
            q.pop();
        }
        else 
        {
            in[c[i].num]=++sum;
        }
        q.push(c[i]);
    }
    printf("%lld\n",sum);
    for(int i=1;i<=n;i++) printf("%lld\n",in[i]);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//scanf("%lld",&T);
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}

