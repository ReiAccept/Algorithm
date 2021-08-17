#include<iostream>

using namespace std;

int feb[23];
int a,n,m,x;//a人,n站,最后m人,求x站人数

int main()
{
    cin>>a>>n>>m>>x;
    feb[1]=1;
    for(int i=2;i<n;i++)
        feb[i]=feb[i-1]+feb[i-2];
    return 0;
}
