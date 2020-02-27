#include<cstdio>
#include<iostream>

using namespace std;

int la,lb;
int a[103],b[103];
int f[103][103];
int d[6][6]=
{
    {0,0,0,0,0,0},
    {0,5,-1,-2,-1,-3},
    {0,-1,5,-3,-2,-4},
    {0,-2,-3,5,-2,-2},
    {0,-1,-2,-2,5,-1},
    {0,-3,-4,-2,-1,0}
};

int read()
{
    char c;cin>>c;
    if(c=='A')return 1;
    if(c=='C')return 2;
    if(c=='G')return 3;
    if(c=='T')return 4;
    return 0;//Make Complier Happy
}

int main()
{
    cin>>la;
    for(int i=1;i<=la;i++) a[i]=read();
    cin>>lb;
    for(int i=1;i<=lb;i++) b[i]=read();
    for(int i=1;i<=la;i++) f[i][0]=f[i-1][0]+d[a[i]][5];
    for(int i=1;i<=lb;i++) f[0][i]=f[0][i-1]+d[5][b[i]];
    for(int i=1;i<=la;i++)
        for(int j=1;j<=lb;j++)
            f[i][j]=max(f[i-1][j-1]+d[a[i]][b[j]],max(f[i-1][j]+d[a[i]][5],f[i][j-1]+d[5][b[j]]));
    cout<<f[la][lb]<<endl;
}
