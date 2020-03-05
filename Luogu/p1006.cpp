#include<cstdio>
#include<iostream>

using namespace std;

int m,n;
int g[55][55];
int f[55][55][55][55];

inline int maxx(int a,int b,int c,int d)
{
    return max(a,max(b,max(c,d)));
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
                scanf("%d",&g[i][j]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                for(int l=j+1;l<=n;l++)
                    f[i][j][k][l]=g[i][j]+g[k][l]+maxx(f[i-1][j][k-1][l],f[i][j-1][k-1][l],f[i-1][j][k][l-1],f[i][j-1][k][l-1]);
    cout<<maxx(f[m-1][n][m-1][n],f[m-1][n][m][n-1],f[m][n-1][m-1][n],f[m][n-1][m][n-1])<<endl;
    return 0;
}
