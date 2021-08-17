#include<iostream>

using namespace std;

int n,ans;
int t[103],dpmax[103],dpmin[103];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(t[i]>t[j])
                dpmax[i]=max(dpmax[i],dpmax[j]+1);
    for(int i=n;i>=1;i--)
        for(int j=n+1;j>i;j--)
            if(t[i]>t[j])//这里的i和j枚举顺序是从后往前,所以还是t[i]>t[j]
                dpmin[i]=max(dpmin[i],dpmin[j]+1);
    for(int i=1;i<=n;i++)
        ans=max(ans,dpmin[i]+dpmax[i]-1);
    cout<<n-ans<<endl;
    return 0;
}
