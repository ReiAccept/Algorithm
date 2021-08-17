#include<bits/extc++.h>
#include<bits/stdc++.h>
#define int long long
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m,ans;
int g[103][103],p[100];

void work()
{
    n=read();m=read();ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            g[i][j]=read();
    for(int i=1;i<=(n/2)+(n&1);i++)
    {
        for(int j=1;j<=(m/2)+(m&1);j++)
        {
            int tot=0;
            tot++,p[tot]=g[i][j];
            if(n-i+1 !=i)tot++,p[tot]=g[n-i+1][j];
            if(m-j+1!=j) tot++,p[tot]=g[i][m-j+1];
            if(n-i+1!=i && m-j+1!=j)tot++,p[tot]=g[n-i+1][m-j+1];
            sort(p+1,p+1+tot);
            for(int k=1;k<=tot/2;k++) ans+=p[k+tot/2]-p[k];
        }
    }
    cout<<ans<<endl;
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
