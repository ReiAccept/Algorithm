#include<iostream>

using namespace std;

int t,m;
int v[10003],w[10003],f[100003];

int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=m;i++)
        for(int j=w[i];j<=t;j++)
            f[j]=max(f[j-w[i]]+v[i],f[j]);
    cout<<f[t]<<endl;
    return 0;
}
