#include<iostream>

using namespace std;

int n,k,ans;
int x[23];

bool isprime(int a)
{
    for(int i=2;i*i<=a;i++)if(a%i==0)return false;
    return true;
}

void dfs(int sum,int cur,int deep)
{
    if(deep==k)
    {
        if(isprime(sum))ans++;
        return;
    }
    for(int i=cur+1;i<=n;i++)dfs(sum+x[i],i,deep+1);
    return;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n-k+1;i++)dfs(x[i],i,1);
    cout<<ans<<endl;
    return 0;
}
