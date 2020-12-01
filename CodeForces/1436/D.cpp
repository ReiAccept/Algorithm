#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

const int N=200003;

int tot,head[N];
struct {int nxt,to;}e[N];
void add(int u,int v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;}

int n;
int val[N], siz[N], dp[N], leaf[N];

void dfs(int u,bool flag=true)
{
    for(int i=head[u];i;i=e[i].nxt)
    {
        dfs(e[i].to);
        flag=false;
    }
    if(flag) leaf[u]=1; 
    siz[u]=val[u];
    for(int i=head[u];i;i=e[i].nxt) 
    {
        int v=e[i].to;
        dp[u]=max(dp[v], dp[u]);
        siz[u]+=siz[v];
        leaf[u]+=leaf[v];
    }
    dp[u]=max(dp[u],(siz[u]+leaf[u]-1)/leaf[u]);
}

void work()
{
    n=read();
    for(int i=2;i<=n;i++) add(read(),i);
    for(int i=1;i<=n;i++) val[i]=read();
    dfs(1);
    cout<<dp[1]<<endl;
    return;
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
