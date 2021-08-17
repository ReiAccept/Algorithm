#include <iostream>
using namespace std;
long long m,n;
long long quickpower(long long x)
{
    if (!x)
        return 1;
    long long ls=quickpower(x>>1);
    if (x&1)
        return (ls*ls*m)%100003;
    else
        return (ls*ls)%100003;
}
int main()
{
    cin>>m>>n;
    m%=100003;
    long long ans=quickpower(n);
    m--;
    ans-=((m+1)*quickpower(n-1))%100003;
    cout<<(ans+100003)%100003<<endl;
    return 0;
}
