#include <iostream>

using namespace std;

int main()
{
    int n,sum=0,flag=0;
    cin>>n;
    int jm[n];
    for(int i=0;i<n;i++)
    {
        cin>>jm[i];
        if(jm[i]>flag)
            sum+=jm[i]-n;
        flag=jm[i];
    }
    cout<<sum<<endl;
}
/*
int main()
{
    int n,a,last=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a>last)ans+=(a-last);
        last=a;
    }
    cout<<ans<<endl;
}
*/