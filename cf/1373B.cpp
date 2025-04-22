#include<iostream>

using namespace std;

int t,a,b;
string str;

int main()
{
    cin>>t;
    while(t--)
    {
        a=0,b=0;
        cin>>str;
        for(int i=0;i<str.size();i++)
            if(str[i]=='1')a++;
            else b++;
        if(a>b)swap(a,b);
        if(a%2==1)cout<<"DA"<<endl;
        else cout<<"NET"<<endl;
    }
    return 0;
}
