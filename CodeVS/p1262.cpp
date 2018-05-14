#include <iostream>

using namespace std;

int main()
{

    int n;
    cin>>n;
    if(n<4)
    {
        cout<<0;
    }
    else
    {
        cout<<(n-1)*(n-2)*(n-3)/6;
    }
    cout<<endl;
    return 0;
}