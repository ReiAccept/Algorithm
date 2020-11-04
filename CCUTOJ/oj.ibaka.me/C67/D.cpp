#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m,l=1,r=1,k=1,ans=1000005,rans,lans;
int a[1000005],b[2005];

void work()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    b[a[1]]=1;
    while(l<=r && r<=n)
    {
        if(k==m)
        {
            if(ans>r-l+1) ans=r-l+1,rans=r,lans=l;
            b[a[l]]--;
            if(b[a[l]]==0) k--;
            l++;
        }
        else
        {
            r++;
            b[a[r]]++;
            if(b[a[r]]==1) k++;
        }
    }
    printf("%d %d\n",lans,rans);
    return;
}

signed main()
{
    int T = 1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
//给定序列有n个数字为1-m的乱序重复,n<=1000000,m<=2000
//求1-n中包含1-m的最短序列的LR,有多解情况下输出最小L
/*
用两个变量l和r来枚举区间
如果l到r的区间不满足要求,r++
如果l到r的区间满足要求,比较ans大小l++
类似滑动窗口的贪心
*/
