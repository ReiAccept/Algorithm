#include<cstdio>
#include<algorithm>

int n,x,y,val;
int a[11][11],f[21][11][11];//a存图,f[k][i][j]走到第k步,第一条路向右走了i步,第二条路向右走了j步

using namespace std;

int main()
{
    scanf("%d",&n);
    while(scanf("%d%d%d",&x,&y,&val),x || y || val)
        a[x][y]=val;
    for(int k=1; k<=2*n-1; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(k>=i && k>=j)
                {
                    f[k][i][j]=max(f[k-1][i][j],max(f[k-1][i-1][j],max(f[k-1][i][j-1],f[k-1][i-1][j-1])));//都下1,两种分别右1下1,都右1
                    if(i==j)//是否走到了同一点,走到同一点取一个数就够了,不在同一个点的话两个数都加上
                        f[k][i][j]+=a[i][k+1-i];
                    else
                        f[k][i][j]=f[k][i][j]+a[i][k+1-i]+a[j][k+1-j];
                }
    printf("%d\n",f[2*n-1][n][n]);
    return 0;
}
