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
/*
手玩样例找规律发现,前k个点肯定和前k个点互相连边。后n-k个点肯定不会连到前k个点里面去。
只要计算前k个点连接的方案,后n-k个点,只要连的是后n-k个点.连接方式随意,方案数是(n-k)^(n-k)最后把两部分方案数乘起来
*/
