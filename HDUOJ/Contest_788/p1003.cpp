#include <iostream>
#include <cstdio>

using namespace std;
int t,n,k;
long long sum[10005];
int a[10005];
bool flag;
int main()
{
    cin>>t;
    while(t--)
    {
        flag=true;
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i-1];
        }
        for(int i=1; flag && i<=n; i++)
            for(int j=i; flag && j<=n; j++)
                if(sum[j]-sum[i]==k)
                {
                    cout<<i<<" "<<j-1<<endl;
                    flag=false;
                }
    }
    return 0;
}
