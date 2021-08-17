#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int a[100003];

void work()
{
    int n=read(),maxn=-1e9,ans=0,cnt=0;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,a[i]);
        ans=max(ans,maxn-a[i]);
    }
    while(ans)
    {
        ans>>=1;
        cnt++;
    }
    printf("%d\n",cnt);
    return;
}

signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}

/*
https://www.luogu.com.cn/blog/ScanfN/solution-cf1338a
有点神仙
对每一个a[i]加上max(a[j]-a[i]) (1<=j<=i) 就可以得到一个不下降序列 kmax=max(a[j]-a[i])
kamax<=2^x -1 所以kmax的二进制位数就是要求的值
题意中要求加上∑2^(j-1)成为不下降序列m那么因为
*/
