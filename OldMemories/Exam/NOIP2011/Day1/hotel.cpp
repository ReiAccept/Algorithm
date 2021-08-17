#include<cstdio>

using namespace std;

int n,k,p,sd,xf,tmp,ans;
int same_last[55],same_before[55],same_now[55];

int main()
{
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d%d",&n,&k,&p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&sd,&xf);
        if (xf<=p)
            tmp=i;
        if (tmp >= same_last[sd])
            same_now[sd] = same_before[sd];
        same_last[sd] = i;
        ans += same_now[sd];
        same_before[sd]++;
    }
    printf("%d",ans);

    return 0;
}
/*
struct hotel
{
    int sd,xf;
} E[20005];

int n,k,p,ans,cant;

/*数学方法。。但是写不对QAQ
int main()
{
    freopen("hotel.in","r",stdin);
    //freopen("hotel.out","w",stdout);
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&E[i].sd,&E[i].xf);
        if(E[i].xf<=p)
            cant++;
    }
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(E[i].sd==E[j].sd)
                ans++;
    printf("%d",ans-cant);
    return 0;
}
*/
/*原版的N^2算法
int main()
{
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&E[i].sd,&E[i].xf);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if(E[i].sd!=E[j].sd)
                continue;
            for(int fuck=i; fuck<=j; fuck++)
            {
                if(E[fuck].xf<=p)
                {
                    ans++;
                    break;
                }
            }
        }
    printf("%d",ans);
    return 0;
}
*/
