#include<cstdio>
#include<algorithm>

using namespace std;

int L,n,m;
int s[500003];
int left,right,mid,c,ans,pos;

bool judge(int x)
{
    ans=pos=0;
    for(int i=1; i<=n; i++)
        if(s[i]-s[pos]<=x && s[i+1]-s[pos]>x)
        {
            ans++;
            pos=i;//更新起点
        }
    ans++;
    if(ans<=m)
        return true;//可行返回真
    else
        return false;//不可行返回假
}

int main()
{
    while(~scanf("%d%d%d",&L,&n,&m))
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&s[i]);
        s[n+1]=L,s[0]=0;                                ///1->L
        sort(&s[1],&s[n+1]);//我可QTMD指针算式,直接地址不好?
        left=0,right=L;                                 ///1->L
        for(int i=1; i<=n+1; i++)
            if(s[i]-s[i-1]>left)
                left=s[i]-s[i-1];
        while(right>=left)
        {
            mid=(left+right)/2;
            if(judge(mid))
            {
                c=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        printf("%d\n",c);
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int s[500010];
int l,n,m;
int judge(int x)
{
    int ans=0;
    int pos=0;
    for(int i=1; i<=n; i++)
    {
        if(s[i]-s[pos]<=x&&s[i+1]-s[pos]>x)
        {
            ans++;
            pos=i;//更新起点
        }
    }
    ans++;
    if(ans<=m)
        return 1;//可行返回真
    else
        return 0;//不可行返回假
}
int main()
{
    int left,right,mid,c,max;
    while(~scanf("%d%d%d",&l,&n,&m))
    {
        s[0]=0;
        for(int i=1; i<=n; i++)
            scanf("%d",&s[i]);
        s[n+1]=l;
        sort(&s[1],&s[n+1]);
        max=0;
        for(int i=1; i<=n+1; i++)
        {
            if(s[i]-s[i-1]>max)
                max=s[i]-s[i-1];
        }
        left=max;//定区间端点
        right=l;
        while(right>=left)
        {
            mid=(left+right)/2;
            if(judge(mid))
            {
                c=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        printf("%d\n",c);
    }
    return 0;
}
*/

/*
 题意：一条长为L的河, 已知N个石头到河的一边的距离,问跳M次到另一边的最小的距离
重要的是找到查找对象,本题是要查找判断mid是否满足跳跃次数是否<=m,
*/
