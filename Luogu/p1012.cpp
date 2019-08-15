#include<iostream>
#include<algorithm>

using namespace std;

int n;
string a[23];

bool cmp(string a,string b)
{
    return a+b>b+a;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        cout<<a[i];
    return 0;
}
