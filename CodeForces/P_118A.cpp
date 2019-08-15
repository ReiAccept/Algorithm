#include<iostream>

using namespace std;

string str;

bool checkit(char x)
{
    if(x!='a' && x!='e' && x!='i' && x!='o' && x!='u' && x!='y')return true;
    return false;
}

int main()
{
    cin>>str;
    for(int i=0;i<str.size();i++)
        if(str[i]>='A' && str[i]<='Z')str[i]+=('a'-'A');
    for(int i=0;i<str.size();i++)
        if(checkit(str[i]))cout<<'.'<<str[i];
    return 0;
}
