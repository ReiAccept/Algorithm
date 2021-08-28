#include<bits/stdc++.h>

//#define int long long

using namespace std;
int T,n,ans;
signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    //scanf("%lld",&t);
    cin>>T;
    while(T--)
    {
        //scanf("%lld",&n); 
        cin>>n;
        ans=0;
        for(int i=1; ; i++)
            if(2*i>n)
            {
                ans=n-i+1;
                break;
            }
        for(int i=(n-1)/3;; i++)
            if(3*i+1>n)
            {
                if(n%2!=i%2) ans+=(n-i+1)/2;
                else if(n%2==1) ans+=((n-i+2)/2);
                else ans+=((n-i+1)/2);
                break;
            }
        //printf("%lld\n",ans);
        cout<<ans<<endl;
    }
    return 0;
}
