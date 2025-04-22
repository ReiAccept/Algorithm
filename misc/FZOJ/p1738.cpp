#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string fuck;
int flag;
int res;

int main()
{
    char a[256],t[256];
    int x=0;
    cin>>a;
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]=='(')
        {
            x++;
            t[x]='(';
        }
        if(a[i]=='[')
        {
            x++;
            t[x]='[';
        }
        if(a[i]==')')
        {
            if(t[x]=='(')
            {
                x--;
            }
            else
                x++;
        }
        if(a[i]==']')
        {
            if(t[x]=='[')
                x--;
            else
                x++;
        }
    }
    if(x==0)
        cout<<"OK"<<endl;
    else
        cout<<"Wrong"<<endl;
    return 0;
}
