#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

char g[203][203];

void work()
{
    int n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    if((g[1][2]==g[2][1]) && (g[n-1][n]==g[n][n-1]) && (g[1][2]!=g[n-1][n]))
    {
        printf("0\n");
        return;
    }
    if(g[1][2]==g[2][1])
    {
        if(g[n-1][n]==g[n][n-1]) printf("2\n1 2\n2 1\n");
        else if(g[n-1][n]==g[1][2]) printf("1\n%d %d\n",n-1,n);
        else printf("1\n%d %d\n",n,n-1);
    }
    else
    {
        if(g[n-1][n]==g[n][n-1])
        {
            if(g[1][2]==g[n-1][n])printf("1\n1 2\n");
            else printf("1\n2 1\n");
        }
        else
        {
            if(g[1][2]!=g[n-1][n])printf("2 \n1 2\n%d %d\n",n-1,n);
            if(g[1][2]!=g[n][n-1])printf("2 \n1 2\n%d %d\n",n,n-1);
        }
    }
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
