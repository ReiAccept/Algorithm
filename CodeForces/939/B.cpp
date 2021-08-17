#include<iostream>
#define MDZZ 1000000000000000001

using namespace std;

long long now,a,b,k,minn=MDZZ,minm=MDZZ,minans=MDZZ;

int main()
{
    cin>>b>>k;
    for(long long i=1;i<=k;i++)
    {
        cin>>a;
        now=b%a;
        if(now<minans)
        {
            minm=i;
            minn=b/a;
            minans=now;
        }
    }
    cout<<minm<<" "<<minn;
}
