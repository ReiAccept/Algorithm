#include<bits/stdc++.h>

using namespace std;

int n,b,ans,sum;
int h[20003];

int main()
{
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>h[i];
    sort(h+1,h+1+n);
    for(int i=n;i>=1;i--)
    {
        if(ans<b)
        {
            ans+=h[i];
            sum++;
        }
        else break;
    }
    cout<<sum<<endl;
    return 0;
}
