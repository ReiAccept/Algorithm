#include <iostream>

using namespace std;

int t,n,m;

int main ()
{
    cin >> t;
    while (t--)
    {
        cin>>n>>m;
        int cnt = 0;
        for(int i=0;i<=n;i++) for(int j=0;j<=n-i;j++) if (i+j*2+(n-i-j)*5==m) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
