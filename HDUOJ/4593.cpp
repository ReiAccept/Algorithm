#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,a[1005];

int main()
{
    while(cin >> n)
    {
        memset(a, 0, sizeof(a));
        for(int i=0; i<=n;i++)
        {
            int x;
            cin>>x;
            a[x]++;
        }
        for(int i=1;i<=n;i++)
            if(a[i]==2)
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}
