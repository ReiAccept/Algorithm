#include<iostream>

using namespace std;

string str;
bool flag;

int main()
{
    cin>>str;
    for(int i=str.size()-1;i>=0;i--)
        if(flag || str[i]!='0')
        {
            cout<<str[i];
            flag=true;
        }
    return 0;
}
