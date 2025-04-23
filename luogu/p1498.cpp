#include<cstdio>
#include<iostream>

using namespace std;

int n,l=4,k=1;
char g[1030][2050];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<=1024;i++)for(int j=0;j<=2048;j++)g[i][j]=' ';
    g[0][0]=g[1][1]='/',g[0][1]=g[0][2]='_',g[0][3]=g[1][2]='\\';
    while(k<n)
    {
        for(int i=0;i<(l>>1);i++)
            for(int j=0;j<l;j++)
                g[i+(l/2)][j+(l/2)]=g[i][j+l]=g[i][j];
        l<<=1,k++;
    }
    for(int i=(l>>1)-1;i>=0;i--)
    {
        for(int j=0;j<l;j++)printf("%c",g[i][j]);
        printf("\n");
    }
    return 0;
}
