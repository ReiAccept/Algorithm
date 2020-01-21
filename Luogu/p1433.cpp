#include<cmath>
#include<cstdio>
#include<iostream>

using namespace std;

int n;
bool vis[20];
double ans=99999999;
double x[20],y[20];
double dis[20][20];

void dfs(int now,int cur,double len)
{
    if(len>ans) return;
    if(now==n)
    {
        ans=min(ans,len);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            dfs(now+1,i,len+dis[cur][i]);
            vis[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    dfs(0,0,0);
    printf("%.2f\n",ans);
    return 0;
}
