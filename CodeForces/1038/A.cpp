#include<cstdio>
#include<iostream>

using namespace std;

int n,k,minn=INT_MAX;
int a[30];
string s;

int main()
{
    cin>>n>>k>>s;
    for(unsigned int i=0;i<s.size();i++) a[s[i]-'A'+1]++;
    for(int i=1;i<=k;i++) minn=min(minn,a[i]);
    cout<<minn*k<<endl;
    return 0;
}
