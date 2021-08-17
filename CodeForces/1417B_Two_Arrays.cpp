#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int a[100003];

void work()
{
    int n=read(),T=read(),flag=0;
    for(int tmp,i=1;i<=n;i++)
    {
        tmp=read();
        if(tmp*2<T)printf("1 ");
        else if(tmp*2>T)printf("0 ");
        else
        {
            printf("%d ",flag);
            flag^=1;
        }
    }
    printf("\n");
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
//大于小于分开放就行,正好T/2的话就各方一边
