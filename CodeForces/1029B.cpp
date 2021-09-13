#include<iostream>

using namespace std;

int n,cnt=1,res=1;
int a[200003];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++)
    {
        if(2*a[i]>=a[i+1]) cnt++;
        else
        {
            res=(cnt>res)?cnt:res;
            cnt=1;
        }
    }
    if(cnt>res) res=cnt;
    cout<<res<<endl;
    return 0;
}
