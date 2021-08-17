#include<iostream>

using namespace std;

long long n,m;
const long long MOD=1e9+7;

long long qpow(long long a, long long b)
{
    long long t = 1;
    while(b)
    {
        if(b & 1) t = t * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return t;
}

int main()
{
    cin>>n>>m;
    cout<< qpow((qpow(2,m)-1+MOD)%MOD,n) <<endl;
    return 0;
}
