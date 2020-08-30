#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n!=0)
    {
        for(int i=1; i<=n+1; i++)cout<<"*";
        cout<<endl;
        for(int i=1; i<=n-1; i++)
        {
            cout<<"*";
            for(int i=1; i<=n-1; i++)cout<<" ";
            cout<<"*"<<endl;
        }
        for(int i=1; i<=n+1; i++)cout<<"*";
        cout<<endl;
        for(int i=1; i<=n-1; i++)
        {
            cout<<"*";
            for(int i=1; i<=n-1; i++)cout<<" ";
            cout<<"*"<<endl;
        }
        for(int i=1; i<=n+1; i++)cout<<"*";
        cout<<endl<<endl;
        cin>>n;
    }
    return 0;
}
