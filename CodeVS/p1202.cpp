#include <iostream>

using namespace std;

int main()
{
    long long n,w=0,k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>n;
        w+=n;
    }
    cout<<w<<endl;
    return 0;
}