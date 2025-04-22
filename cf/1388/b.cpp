#include<cstdio>
#include<iostream>

using namespace std;

int T,n;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            if((n%4 && i==n-n/4) || i>n-n/4) cout<<8;
            else cout<<9;
        cout<<endl;
    }
    return 0;
}

