#include<bits/stdc++.h>

using namespace std;

int n,x1,x2;
bool vis[1003];

int main()
{
    cin>>n;cin>>x1;
    for(int i=2;i<=n;i++)
    {
        cin>>x2;
        if(abs(x1-x2)<=n)vis[abs(x1-x2)]=true;
        else
        {
            cout<<"Not jolly"<<endl;
            return 0;
        }
        x1=x2;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(!vis[i])
        {
            cout<<"Not jolly"<<endl;
            return 0;
        }
    }
    cout<<"Jolly"<<endl;
    return 0;
}
