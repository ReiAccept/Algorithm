#include<cstdio>
#include<iostream>

using namespace std;

int n,m,x,y,r,z;
int g[503][503],gx[503][503];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;1<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=(i-1)*n+j-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y,&r,&z);
        if(z)//逆时针
        {

        }
        else //顺时针
        {

        }
    }
    return 0;
}
