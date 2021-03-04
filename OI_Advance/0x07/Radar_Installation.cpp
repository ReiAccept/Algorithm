#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef long double reald;

const reald eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF

int n,d,sum;
struct Node{
    reald l,r;
    Node(){l=r=0;}
    Node(int x,int y)
    {
        reald t=sqrt(d*d-y*y);
        l=x-t,r=x+t;
    }
    bool operator < (const Node &b) const
    {
        if(l==b.l) return r<b.r;
        return l<b.l;
    }
};

void work()
{
    vector<Node> a;reald pos=-INF;sum=0;
    a.pb(Node());
    for(int x,y,i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x,&y);
        if(abs(y)>d)
        {
            printf("-1");
            return;
        }
        a.pb(Node(x,y));
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++)
    {
        if(pos+eps<a[i].l)
        {
            sum++;
            pos=a[i].r;
        }
        else pos=min(a[i].r,pos);
    }
    printf("%lld\n",sum);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    signed T=1;//scanf("%d",&T);
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        scanf("%lld%lld",&n,&d);work();//AcWing
        //while(scanf("%lld%lld",&n,&d) && n && d) work();//Nowcoder
    }
    return 0;
}

/*
雷达都在还海岸线上,那么题目意思就是给定N个区间,在x轴上放置最少的点，使每个区间包含至少一个点
也就是从小岛向周围为d范围内的x轴上位置打点,求最小点数 
*/
