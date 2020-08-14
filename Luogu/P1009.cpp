#include<bits/stdc++.h>

using namespace std;

int n,m=100;
int a[103]= {0,1},b[103],ans[103];

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int jw=0,j=1; j<=100; j++)
        {
            a[j]=a[j]*i+jw;
            jw=a[j]/10;
            a[j]%=10;
        }
        for(int jw=0,j=1; j<=100; j++)
        {
            ans[j]+=a[j]+jw;
            jw=ans[j]/10;
            ans[j]%=10;
        }
    }
    while(!ans[m]) m--;
    for(; m>=1; m--) cout<<ans[m];
}
