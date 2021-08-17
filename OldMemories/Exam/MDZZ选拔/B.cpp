#include <iostream>

using namespace std;

int c,m,n;
long long a[21],b[21];

int main()
{
    ios::sync_with_stdio(false);
    cin>>c;
    b[1]=b[2]=1;b[3]=2;
    for(int i=4;i<21;++i) b[i]=(i-1)*(b[i-1]+b[i-2]);
    a[0]=1;
    for(int i=1;i<22;++i) a[i]=a[i-1]*i;
    while(c--)
    {
        cin>>n>>m;
        cout<<(a[n]/(a[m]*a[n-m]))*b[m]<<endl;
    }
    return 0;
}
