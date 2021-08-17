#include <iostream>

using namespace std;

void move1(int n,char a,char b,char c);

int k;

int main()
{
    int i;
    cin>>i;
    move1(i,'a','b','c');
    return 0;
}

void move1(int n,char a,char b,char c)
{
    if(1==n)
        {
        k++;
        cout<<k<<":"<<a<<"->"<<c<<endl;
        }
    else
        {
            move1(n-1,a,c,b);
            k++;
            cout<<k<<":"<<a<<"->"<<c<<endl;
            move1(n-1,b,c,a);
        }
}