#include <bits/stdc++.h>

using namespace std;

long long n,a[200009],b[200009],ans,in[200009],vis[200009],l=1,r;
queue<long long>q;

int main()
{
    cin>>n;
    r=n;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=n; i++)cin>>b[i];
    for(int i=1; i<=n; i++)if(~b[i])in[b[i]]++;
    for(int i=1; i<=n; i++)if(!in[i])q.push(i);
    for(int i=1; i<=n; i++)
    {
        long long x=q.front();
        q.pop();
        ans=ans+a[x];
        if(a[x]>=0)
        {
            vis[l++]=x;
            a[b[x]]+=a[x];
        }
        else vis[r--]=x;
        if(~b[x])
        {
            in[b[x]]--;
            if(!in[b[x]])q.push(b[x]);
        }
    }
    cout<<ans<<endl;
    for(int i=1; i<=n; i++)cout<<vis[i]<<" ";
    return 0;
}

