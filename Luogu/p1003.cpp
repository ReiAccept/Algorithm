#include<cstdio>

using namespace std;

int n,x,y;

struct Edge
{
    int a,b,g,k;
} g[10003];

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d%d%d",&g[i].a,&g[i].b,&g[i].g,&g[i].k);
    scanf("%d%d",&x,&y);
    g[0].a=g[0].b=g[0].g=g[0].k=-1;
    for(int i=n; i>=0; i--)
        if(g[i].a<=x && g[i].b<=y && (g[i].a+g[i].g)>=x && (g[i].b+g[i].k)>=y)
        {
            printf("%d",i);
            return 0;
        }
        else if(i==0)
            printf("-1");
    return 0;
}
