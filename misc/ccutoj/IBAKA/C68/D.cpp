#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,q,x,y;

void work()
{
    n=read();q=read();
    while(q--)
    {
        x=read();y=read();
        if(x==y)
        {
            printf("0\n");
            continue;
        }
        if(__gcd(x,y)==1)printf("1\n");
        else printf("2\n");//这尼玛,1-n的gcd是1,所以随便a-1-b就是2
    }
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
