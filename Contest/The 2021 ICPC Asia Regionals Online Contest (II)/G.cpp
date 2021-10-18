#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
int a[100010],b[100010];
int sum,tot=1;
signed main()
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(t==1)
    {
        for(int i=1;i<=n;i++)
        {
            tot=tot*a[i]*b[i];
        }
        cout<<tot;
    }
    else if(t==0) cout<<0;
    else if(sum>t)cout<<0;
    else if(sum<t)cout<<"infinity";
    else
    {
        for(int i=1;i<=n;i++)
        {
            tot*=pow(b[i],a[i]);
        }
        cout<<tot;
    }
    return 0;
}
