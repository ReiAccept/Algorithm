#include<iostream>

using namespace std;

long long t,n;

long long cp(long long n)
{
    if (n==1)
        return 0;
    if (n==2)
        return 1;
    return (n-1)*(cp(n-2)+cp(n-1));
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<cp(n)<<endl;
    }
    return 0;
}
