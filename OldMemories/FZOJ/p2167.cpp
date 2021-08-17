#include <iostream>
 
using namespace std;

int n;
long long ans,f=1;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        f=f*(n-i+1);
        ans+=f;
    }
    cout<<ans-1<<endl;
    return 0;
}
