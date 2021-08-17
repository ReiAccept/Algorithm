#include<iostream>

using namespace std;

long long q_pow(long long b,long long p,long long k)
{
    long long ans=1;
    while(p>0)
    {
        if(p&1)
            ans=ans*b%k;
        b=b*b%k;
        p>>=1;
    }
    return ans%k;
}

int main()
{
    long long b,p,k;
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<q_pow(b,p,k)<<endl;
    return 0;
}
