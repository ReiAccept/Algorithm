#include <cstdio>
#include <algorithm>

#define Maxn 100010
using namespace std;

struct Node{
    int xi,yi;
    double si;
}road[Maxn];

double S,si,sum;
int n,m,xi,yi,num,flag;
int cun[Maxn];

bool cmp(Node a,Node b);
int Find(int x);

int main()
{
    scanf("%lf%d",&S,&n);
    while(scanf("%d%d%lf",&xi,&yi,&si)!=EOF)
    {
        ++m;
        road[m].si=si;
        road[m].xi=xi;
        road[m].yi=yi;
    }
    for(int i=1; i<=n; i++)
        cun[i]=i;
    sort(road+1,road+m+1,cmp);
    num=n-1;
    flag=1;
    while(num)
    {
        if(flag==m+1)
            break;
        if(Find(road[flag].xi)!=Find(road[flag].yi))
        {
            int fx=Find(road[flag].xi);
            int fy=Find(road[flag].yi);
            cun[fx]=fy;
            sum+=road[flag].si;
            num--;
        }
        flag++;
    }
    if(S>=sum && !num)
        printf("Need %.2lf miles of cable\n",sum);
    else
        printf("Impossible\n");
    return 0;
}

bool cmp(Node a,Node b)
{
    return a.si<b.si;
}

int Find(int x)
{
    int r=x;
    while(r!=cun[r])
        r=cun[r];
    int tmp=x;
    while(tmp!=r)
    {
        int t=cun[tmp];
        cun[tmp]=r;
        tmp=t;
    }
    return r;
}
