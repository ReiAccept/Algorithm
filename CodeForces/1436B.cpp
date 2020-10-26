#include<bits/stdc++.h>

using namespace std;

int T,n;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                if(j==i||j==i%n+1) cout<<1<<" ";
                else cout<<0<<" ";
            cout<<endl;
        }
    }
    return 0;
}
