#include<iostream>

using namespace std;

int xb,yb,xm,ym;
long long f[30][30];
bool a[30][30];

int main()
{
    cin>>xb>>yb>>xm>>ym;
    xb+=2;yb+=2;xm+=2;ym+=2;
    //cout<<f[2][2]<<endl;
    a[xm][ym]=a[xm-2][ym-1]=a[xm-1][ym-2]=a[xm+1][ym-2]=a[xm+2][ym-1]=a[xm-2][ym+1]=a[xm-1][ym+2]=a[xm+2][ym+1]=a[xm+1][ym+2]=1;
    f[2][2]=1;a[2][2]=1;
    for(int i=2;i<=xb;i++)
    {
        for(int j=2;j<=yb;j++)
        {
            if(!a[i][j]) f[i][j]=f[i-1][j]+f[i][j-1];
            //cout<<f[i][j]<<" ";
            //cout<<i<<" "<<j<<endl;
        }
        //cout<<endl;
    }
    cout<<f[xb][yb]<<endl;
    return 0;
}
