#include<cstdio>
#include<iostream>

using namespace std;

int n;
long long k,f[10003],a[50];

int main()
{
    freopen("champion.in","r",stdin);
    freopen("champion.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    f[0]=1;//妈的智障,这里要把不买票的方案初始化为1
    for(int i=1; i<=n; i++)
        for(int j=k; j>=a[i]; j--)
            f[j]+=f[j-a[i]];
    for(int i=1; i<=k; i++)
        f[i]+=f[i-1];
    cout<<f[k]<<endl;
    return 0;
}
