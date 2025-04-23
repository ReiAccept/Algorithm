#include<iostream>

using namespace std;

const int MOD=100003;

int n,k,ans;
int a[100003];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++) a[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=max(1,i-k);j<i;j++)
            a[i]=(a[i]+a[j])%MOD;
    cout<<a[n]<<endl;
    return 0;
}
