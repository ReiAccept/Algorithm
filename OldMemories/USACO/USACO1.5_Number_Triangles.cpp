#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    int n;
    cin>>n;
    int n2=n*(n+1)/2;
    int sj[n2+1];
    for(int i=1;i<=n2;i++)
        cin>>sj[i];
    for(int i=n-1;i>0;i--)
        for(int j=(1+i)*i/2;j>(1+i)*i/2-i;j--)
            sj[j]=max(sj[j+i],sj[j+i+1])+sj[j];
    cout<<sj[1]<<endl;
    return 0;
}
/*
#include<iostream>

int i,j,n,a[10000][10000];

int main()
{
    cin>>n;
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
    cin>>a[i][j];
        for(i=n-1;i>0;i--)
            for(j=1;j<=i;j++)
                a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
    cout<<a[1][1]<<endl;
}
*/
