#include <iostream>
using namespace std;

double a,b,fuck;

int main()
{
    cin>>a>>b;
    fuck=a-b;
    if(fuck<=1e-8 &&fuck>=-(1e-8))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}