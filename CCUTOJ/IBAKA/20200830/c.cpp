#include<bits/stdc++.h>

using namespace std;

#define int long long

int mp[666][666],arr[666],vis[666];
int n,m,sum;
vector<int> ans;

signed main()
{
    scanf("%lld",&n);
    ans.clear();
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) scanf("%lld",&mp[i][j]);
    for(int i=1; i<=n; i++) scanf("%lld",&arr[i]),vis[i]=0;
    for(int k=n; k>=1; k--)
    {
        vis[arr[k]]=1;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                mp[i][j]=min(mp[i][j],mp[i][arr[k]]+mp[arr[k]][j]);
        if(k==n)
        {
            ans.push_back(0*1ll);
            continue;
        }
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(vis[i]&&vis[j]) sum+=mp[i][j];
        ans.push_back(sum);
    }
    //reverse(ans.begin(),ans.end());
    for(int i=ans.size()-1; i>=0; i--)
    {
        if(!i) printf("%lld",ans[i]);
        else printf(" %lld",ans[i]);
    }
    printf("\n");
    return 0;
}


