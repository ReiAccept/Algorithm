#include<cstdio>
#include<iostream>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,k,ans;
char g[10][10];
bool v[10];

void dfs(int c,int cnt)//c->行数 cnt 棋子数
{
    if(cnt==k)
    {
        ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i] && g[c][i]=='#')
        {
            v[i]=true;
            dfs(c+1,cnt+1);
            v[i]=false;
        }
    }
    if(c<n)dfs(c+1,cnt);
}

void work()
{
    ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    dfs(1,0);
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        while(cin>>n>>k && (n!=-1 && k!=-1)) work();
    }
    return 0;
}
