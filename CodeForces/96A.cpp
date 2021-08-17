#include<iostream>

using namespace std;

int ans=1;
char flag;
string a;

int main()
{
    cin>>a;flag=a[0];
    for(int i=1;i<=a.size();i++)
    {
        if(flag==a[i]) ans++;
        else
        {
            ans=1;
            flag=a[i];
        }
        if(ans>=7)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
