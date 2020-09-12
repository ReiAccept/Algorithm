#include<bits/stdc++.h>

using namespace std;

int n,ans;
int a[10003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=2;i--)
        for(int j=i-1;j>=1;j--)
            if(a[j]>a[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
