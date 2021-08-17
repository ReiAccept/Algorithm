#include<iostream>

using namespace std;

int n,m,ans;
int a[23];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=1;flag && j<=m;j++)
            if(i%a[j]==0)
                flag=false;
        if(flag)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
