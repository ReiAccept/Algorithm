#include<iostream>

using namespace std;

int n,sum;

int main()
{
    cin>>n;
    while(n--)
    {
        int tmp;
        cin>>tmp;
        sum+=tmp;
    }
    cout<<sum<<endl;
    return 0;
}
