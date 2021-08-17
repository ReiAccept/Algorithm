#include<iostream>

using namespace std;

long long n;
const long long MOD=1000000007;

long long power(long long a,long long b)
{
    long long r=1,base=a;
    while(b!=0)
    {
        if(b%2) r=((r*base) % MOD);
        base=base*base%MOD;
        b>>=1;
    }
    return r;
}

int main()
{
    cin>>n;
    cout<<(power(2,(n-1))*n)%MOD<<endl;
    return 0;
}
