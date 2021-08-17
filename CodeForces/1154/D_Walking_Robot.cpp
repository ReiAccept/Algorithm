#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,a,b,ans,maxa;
bool s[200003];

void work()
{
	n=read();b=read();maxa=a=read();
	for(int i=1;i<=n;i++)s[i]=read();
	for(int i=1;i<=n;i++)
	{
		if((!a)&&(!b)) break;
		else if(!a)
        {
            if(s[i])a=min(a+1,maxa);
            b--;
        }
		else if(!b) a--;
		else if(s[i] && a<maxa) 
        {
            if(s[i])a=min(a+1,maxa);
            b--;
        }
		else a--;
		ans++;
	}
	printf("%d\n",ans);
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
