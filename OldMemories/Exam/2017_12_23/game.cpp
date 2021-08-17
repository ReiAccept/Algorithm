#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int s,t;
} ans[100003];

int n,maxn,cnt=1;
int a[100003],G[100003],M[100003];

bool cmp(Node x,Node y)
{
    if(x.s<y.s)
        return 1;
    if(x.s==y.s&&x.t<=y.t)
        return 1;
    return 0;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        G[i]+=G[i-1];
        M[i]+=M[i-1];
        if(a[i]==1)
            G[i]++;
        else
            M[i]++;
    }
    if((a[n]==1 && G[n]<M[n]) || (a[n]==2 && G[n]>M[n]))
    {
        printf("0\n");
        return 0;
    }
    if(G[n]>M[n])
        maxn=G[n];
    else
        maxn=M[n];
    for(int i=1; i<=maxn; i++)
    {
        bool flag=false;
        for(int j=1; j<=maxn; j++)
        {
            if(i*j==maxn)
            {
                ans[cnt].s=j;
                flag=true;
                break;
            }
        }
        if(flag)
            ans[cnt++].t=i;
    }
    cnt--;
    sort(ans+1,ans+cnt+1,cmp);

    printf("%d\n",cnt);

    for(int i=1; i<=cnt; i++)
        printf("%d %d\n",ans[i].s,ans[i].t);
    return 0;
}
/*
1.赢得比赛的人必须是赢得最后一局的人
2.比赛必须进行到最后,即计分要记到n
3.两个人赢得局数不能相等,不能平局
枚举t,对于某个t的值,那么s的值也就确定
*/
