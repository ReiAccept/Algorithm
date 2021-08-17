#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int n2=n*(n+1)/2;
    int sj[n2+1];
    for(int i=1;i<=n2;i++)
        cin>>sj[i];
    for(int i=n-1;i>0;i--)
        for(int j=(1+i)*i/2;j>(1+i)*i/2-i;j--)
            sj[j]=max(sj[j+i],sj[j+i+1])+sj[j];
    cout<<"max="<<sj[1]<<endl;
    return 0;
}
