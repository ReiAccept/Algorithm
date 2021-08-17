#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int l=0,i=0;
    string f[100],k;
    while(cin>>k)
    {
        f[i]=k;
        i++;
    }
    for(i--;i>=0;i--)
    {
        //if(i=0)
        //    cout<<f[i]<<endl;
        //else
            cout<<f[i]<<" ";
    }
    return 0;
}