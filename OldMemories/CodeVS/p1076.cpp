#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int flag[n];
    for(int i=0;i<n;i++)
    {
        cin>>flag[i];
    }
    sort(flag,flag+n);
    for(int i=0;i<n;i++)
    {
        cout<<flag[i]<<" ";
    }
}