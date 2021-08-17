#include<cstdio>
#include<iostream>

using namespace std;

int n,k;
int s[100003],a[100003];
long long ans,tot;

int main()
{
    freopen("dish.in","r",stdin);
    freopen("dish.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1; i<=k; i++)
        tot+=i*a[i];
    ans=tot;
    for(int i=k+1; i<=n; i++)
    {
        tot-=a[i-k];
        tot-=s[i-1]-s[i-k];
        tot+=k*a[i];
        if(tot>ans)
            ans=tot;
    }
    cout<<ans<<endl;
    return 0;
}
