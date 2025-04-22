#include<iostream>
#include<algorithm>

using namespace std;

int n,ans;
string s;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s[1]=='-') ans--;
        if(s[1]=='+') ans++;
    }
    cout<<ans<<endl;
    return 0;
}
