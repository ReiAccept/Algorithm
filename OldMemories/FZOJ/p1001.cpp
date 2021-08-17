#include <iostream>
#include <string>
using namespace std;

int ma(char x);

int main()
{

    int k1=1,k2=1;
    char c;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<=5;i++)
    {
        if(a[i]=='\0')
            break;
        k1=k1*ma(a[i]);
        k1=k1%47;
    }
    
    for(int i=0;i<=5;i++)
    {
        if(b[i]=='\0')
            break;
        k2=k2*ma(b[i]);
        k2=k2%47;
    }
    //k1=k1%47;
    //k2=k2%47;
    if(k1==k2)
        cout<<"GO";
    else
        cout<<"STAY";
    return 0;
}

int ma(char in)
{
    return in-64;
}