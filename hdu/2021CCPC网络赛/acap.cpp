#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i=1; i<=n; i++)
            if(2*i>n)
            {
                ans=n-i+1;
                break;
            }
        for(int i=(n-1)/3;i<=n*3; i++)
            if(3*i+1>n)
            {
                if(n%2!=i%2) ans+=(n-i+1)/2;
                else if(n%2==1) ans+=((n-i+2)/2);
                else ans+=((n-i+1)/2);
                break;
            }
        printf("%lld\n",ans);
    }
    return 0;
}

