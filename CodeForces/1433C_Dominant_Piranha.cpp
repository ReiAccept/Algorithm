#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n;
int a[300003];

void work()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    bool AllSame=true;
    for(int i=2;i<=n && AllSame;i++)if(a[i-1]!=a[i]) AllSame=false;
    if(AllSame)
    {
        printf("-1\n");
        return;
    }
    int maxn=a[1],maxi=1;
    for(int i=2;i<=n-1;i++)
    {
        if(maxn<=a[i] && (a[i]>a[i-1] || a[i]>a[i+1]))maxi=i,maxn=a[i];
    }
    if(a[n]>maxn && a[n]>a[n-1])maxi=n;
    printf("%d\n",maxi);
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
