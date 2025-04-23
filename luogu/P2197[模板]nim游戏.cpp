#include<iostream>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int n,ans;
        cin>>n;
        ans=0;
        for(int x,i=1;i<=n;i++)
        {
            cin>>x;
            ans^=x;
        }
        if(ans)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
