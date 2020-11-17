#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m;

void work()
{
    n=read();m=read();
    int sum=0,cnt=0,minn=9999,ans=0;
    for(int tmp,i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            tmp=read();
            if(tmp<0)cnt++;
            sum+=abs(tmp);
            if(abs(tmp)<minn)minn=abs(tmp);
        }
    if(cnt%2)ans=sum-2*minn;
    else ans=sum;
    printf("%d\n",ans);
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
