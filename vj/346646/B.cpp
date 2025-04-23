#include<iostream>
#include<algorithm>

using namespace std;

long long a2,ans,n,a;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(long long i=1;i<=n;i++)
	{
        cin>>a;
        ans+=abs(a2-a);
        a2=a;
    }
    cout<<ans<<endl;
    return 0;
}
