#include<iostream>

using namespace std;

int n,m,ans;
int f[103][103];
bool g[103][103];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(g[i][j]) ans=max(ans,f[i][j]=min(f[i-1][j],min(f[i-1][j-1],f[i][j-1]))+1);
    cout<<ans<<endl;
    return 0;
}
