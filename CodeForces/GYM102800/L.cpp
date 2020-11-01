#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m,q;
int x[1000003];

void work()
{
    n=read();m=read();q=read();
    for(int i=1;i<=n;i++)x[i]=read();
    while(q--)
    {
        
    }
    return;
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
