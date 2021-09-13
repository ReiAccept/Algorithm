#include<bits/stdc++.h>

using namespace std;

int n,q,k;
int a[1003];

signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cin>>q;
    while(q--)
    {
        cin>>k;
        cout<<a[k]<<endl;
    }
    return 0;
}
