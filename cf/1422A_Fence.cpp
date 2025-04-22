#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int a,b,c;

void work()
{
    a=read();b=read();c=read();
    cout<<a+b+c-1<<endl;
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
已知有一个四边形有三条边的长度分别是a,b,c求另外一条边的可能长度(每条边的长度都为整数)
 */
