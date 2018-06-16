#include<iostream>

using namespace std;

const int MOD=1000000007;
long long n,k,ans;

long long quickpow(long long x,long long p)
{
    long long s=1;
	x=x%MOD;
    while(p)
    {
        if(p&1) 
			s=(s*x)%MOD;
        x=(x*x)%MOD;
        p>>=1;
    }
    return s;
}

int main()
{
    cin>>n>>k;
    ans=(quickpow(k,k-1)*quickpow(n-k,n-k))%MOD;
    cout<<ans<<endl;
    return 0;
}
