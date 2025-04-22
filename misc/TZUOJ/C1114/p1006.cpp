#include<map>
#include<iostream>

using namespace std;

string t1;
int n,m,k,t2,ans;
map<string,int>a;

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2;
        a[t1]=t2;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        a[t1]=-t2;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>t1;
        ans+=a[t1];
    }
    cout<<ans<<endl;
    return 0;
}
