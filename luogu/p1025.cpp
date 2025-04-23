#include<iostream>

using namespace std;

int n,k,ans;

void dfs(int last,int sum,int cur)
{
    if(sum>n)return;
    if(cur==k && sum==n)ans++;
    if(cur==k) return;
    for(int i=last;sum+i*(k-cur)<=n;i++)dfs(i,sum+i,cur+1);
}

int main()
{
    cin>>n>>k;
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}
