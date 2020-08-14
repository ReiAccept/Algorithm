#include<iostream>

using namespace std;

int n,k,ans;
int p[53];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) if(p[i]>0 && p[i]>=p[k]) ans++;
    cout<<ans<<endl;
    return 0;
}
