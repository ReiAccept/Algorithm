#include<cstdio>
#include<iostream>

using namespace std;

int a,b;

int gcd(int a,int b)
{
    if(b) return (gcd(b,a%b));
    return a;
}

int main()
{
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
