#include<iostream>
#include<algorithm>

using namespace std;

int m,n;

int main()
{
    cin>>m>>n;
    if(m%2==0) cout<<(m/2)*n<<endl;
    else if(n%2==0) cout<<(n/2)*m<<endl;
    else
    {
        if(n>m) swap(m,n);
        int ans=m*((n-1)/2);
        ans+=((m-1)/2);
        cout<<ans<<endl;
    }
    return 0;
}
