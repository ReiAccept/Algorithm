#include<iostream>

using namespace std;

long long n,a,b,ans;

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}

int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(lcm(i,j)==n) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

