#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,ans,one,two,thr;

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();
        if(x==4)ans++;
        else if(x==3)thr++;
        else if(x==2)two++;
        else if(x==1)one++;
    }
    ans+=thr;
    one=max(0,one-thr);
    ans+=(two/2);
    two%=2;
    if(two)
    {
        ans++;
        one=max(0,one-2);
    }
    if(one)
    {
        ans+=(one/4);
        one%=4;
        if(one)ans++;
    }
    cout<<ans<<endl;
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
