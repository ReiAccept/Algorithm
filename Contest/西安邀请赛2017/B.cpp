#include<bits/stdc++.h>

using namespace std;

int T,n,k,ans;

int a[200003],b[200003];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]+b[n-i+1]>=k)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}