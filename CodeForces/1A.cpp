#include<cstdio>
#include<iostream>

using namespace std;

long long n,m,a;

int main()
{
    cin>>n>>m>>a;
    long long t1=n/a;
    if(n%a)t1++;
    long long t2=m/a;
    if(m%a)t2++;
    cout<<t1*t2<<endl;
    return 0;
}
