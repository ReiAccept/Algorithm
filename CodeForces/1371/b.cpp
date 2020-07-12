#include<iostream>

using namespace std;

long long t,n,r;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        cout<<(1+min(r,n-1))*min(r,n-1)/2+int(r>=n)<<endl;
    }
    return 0;
}
