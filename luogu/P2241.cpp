#include<bits/stdc++.h>

using namespace std;

long long n,m,zfx;

int main()
{
    cin>>m>>n;
    for(long long i=1;i<=min(m,n);i++)
        zfx+=(m-i+1)*(n-i+1);
    cout<<zfx<<" "<<((m+1)*m/2)*((n+1)*n/2)-zfx<<endl;
    return 0;
}
