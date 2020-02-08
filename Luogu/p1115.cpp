#include<iostream>

using namespace std;

int n,minx,maxx=-0x3f3f3f;
int a[200003],f[200003];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        f[i]=f[i]+f[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=f[i]-minx;
        minx=min(minx,f[i]);
        maxx=max(maxx,a[i]);
    }
    cout<<maxx<<endl;
    return 0;
}
