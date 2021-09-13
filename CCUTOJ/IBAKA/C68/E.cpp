#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int y,d,s;
char c;
char str[100003];

void work()
{
    while((c=(char)getchar()) != EOF)
    {
        if(c=='y')y++;
        else if(c=='d')d++;
        else if(c=='s')s++;
    }
    //printf("1\n");
    int q=min((y/2),min(d,s));
    for(int i=1;i<=q;i++) printf("yyds");
    //printf("2\n");
    y-=(q*2);d-=q;s-=q;
    while(y>0 || d>0 || s>0)
    {
        //printf("%lld %lld %lld\n",y,d,s);
        if(y>0)
        {
            printf("y");
            y--;
        }
        if(y>0)
        {
            printf("y");
            y--;
        }
        if(d>0)
        {
            printf("d");
            d--;
        }
        if(s>0)
        {
            printf("s");
            s--;
        }
    }
    return;
}

signed main()
{
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
