#include<iostream>

using namespace std;

int r;
int g[1003][1003];

int main()
{
    cin>>r;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=i;j++)
            cin>>g[i][j];
    for(int i=r-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            g[i][j]=max(g[i][j]+g[i+1][j],g[i][j]+g[i+1][j+1]);
    cout<<g[1][1]<<endl;
    return 0;
}
