#include<bits/stdc++.h>

using namespace std;

int n,k,ans;
bool vis[20];
char mp[20][20];

int DFS(int x,int y)
{
    if(y>=k)
    {
        ans++;
        return 0;
    }
    for(int i=x;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[j] && mp[i][j]=='#')
            {
                vis[j]=true;
                DFS(i+1,y+1);
                vis[j]=false;
            }
        }
    }
    return 0;
}
int main()
{
    while(cin>>n>>k)
    {
        if(n==-1 && k==-1) break;
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int i=0;i<n;i++) cin>>mp[i];
        DFS(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
