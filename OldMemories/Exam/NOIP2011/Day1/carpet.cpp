#include <cstdio>

#define maxn 10005
using namespace std;
int a[maxn], b[maxn], g[maxn], k[maxn], n, x, y;

int main()
{
    freopen("carpet.in", "r", stdin);
    freopen("carpet.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);

    scanf("%d%d", &x, &y);
    int ans = -1;
    for (int i = n; i >= 1 && ans == -1; --i)
        if (a[i]<=x&&x<=a[i]+g[i] && b[i] <= y && y <= b[i] + k[i])
            ans=i;
    printf("%d\n", ans);

    return 0;
}
/*
#include<cstdio>

using namespace std;

int n,resa,resb;

struct dt
{
    int a,b;
    int x,y;
} G[10005];

int main()
{
    freopen("carpet.in","r",stdin);
    freopen("carpet.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d%d%d",&G[i].a,&G[i].b,&G[i].x,&G[i].y);
    scanf("%d%d",&resa,&resb);

    for(int i=n; i>=1; i--)
        if((G[i].a<=resa)&&((G[i].a+G[i].x)>=resa)&&(G[i].b<=resb)&&((G[i].b+G[i].y)>=resb))
        {
            printf("%d",i);
            return 0;
        }
    printf("-1");
    return 0;
}
*/
