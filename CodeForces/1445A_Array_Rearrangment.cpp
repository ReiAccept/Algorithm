#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,x;
int a[53],b[53];

void work()
{
    n=read();x=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    sort(a+1,a+1+n);
    sort(b+1,b+1+n,[](int x,int y){
            return x>y;
            });
    for(int i=1;i<=n;i++)
    {
        if(a[i]+b[i]>x)
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
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
