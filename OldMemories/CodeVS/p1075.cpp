#include <iostream>
#include <set>
using namespace std;

int main()
{
    int k,j,l=0;
    set<int> number;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>j;
        number.insert(j);
    }
    for(set<int>::iterator it=number.begin();it!=number.end();it++)
    {
        l++;
    }
    cout<<l<<endl;
    for(set<int>::iterator it=number.begin();it!=number.end();it++)
    {
        cout<<*it<<" ";
    }
}