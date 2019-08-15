#include<iostream>

using namespace std;

struct DT
{
    int a,b,g,k;
}a[10003];

int n,x,y;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].a>>a[i].b>>a[i].g>>a[i].k;
    cin>>x>>y;
    for(int i=n;i>=1;i--)
    {
        if(a[i].a<=x && a[i].b<=y && x<=(a[i].a+a[i].g) && y<=(a[i].b+a[i].k))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
