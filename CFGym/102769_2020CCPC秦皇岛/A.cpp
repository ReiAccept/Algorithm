#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int r,b;

void work()
{
    r=read();b=read();
    int x=r*(r-1),y=(r+b)*(r+b-1);
    int gcdxy=__gcd(x,y);
    x/=gcdxy;
    y/=gcdxy;
    if(x==0)printf("0/1\n");
    else printf("%d/%d\n",x,y);
    return;
}

signed main()
{
    int T = read();
	for(int Case=1;Case<=T;Case++)
    {
        printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
