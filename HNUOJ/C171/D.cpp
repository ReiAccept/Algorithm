#include<iostream>

using namespace std;

int a;
bool k3,k5,k7;

int main()
{
    cin>>a;
    if(a%3==0)
        k3=true;
    if(a%5==0)
        k5=true;
    if(a%7==0)
        k7=true;
    if(k3)
        cout<<"3"<<" ";
    if(k5)
        cout<<"5"<<" ";
    if(k7)
        cout<<"7"<<" ";
    if(!k3 && !k5 && !k7)
        cout<<"n"<<endl;
    return 0;
}
