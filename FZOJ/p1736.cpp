#include <iostream>
#include <cstdio>
#define Maxn 19
#define Maxm 29

using namespace std;

int dat[Maxn][Maxm];
int f[Maxn][Maxm];
int n,m,max1;

void out(int a,int b);

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&dat[i][j]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            //f[i][j]= max(f[i-1][k] +dat[i][j-k]) 0<=k<=j
            int maxt=0;
            for(int k=0; k<=j; k++)
            {
                if(f[i-1][k]+dat[i][j-k]>maxt)
                {
                    maxt=f[i-1][k]+dat[i][j-k];
                }
            }
            f[i][j]=maxt;
        }
    }
    printf("%d\n",f[n][m]);
    max1=f[n][m];
    out(n,m);
    return 0;
}

void out(int i,int j)
{
    if(i==0)
    {
        return ;
    }
    for(int k=0; k<=j; k++)
    {
        if(f[i-1][k]+dat[i][j-k]==max1)
        {
            max1=f[i-1][k];
            out(i-1,k);
            printf("%d %d\n",i,j-k);
            break;
        }
    }
}
