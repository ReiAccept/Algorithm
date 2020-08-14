#include<iostream>

using namespace std;

int n;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        cin>>str;
        if(str.size()<=10) cout<<str<<endl;
        else
        {
            cout<<str[0]<<str.size()-2<<str[str.size()-1]<<endl;
        }
    } 
    return 0;
}
