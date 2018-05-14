#include<cstdio>

long  f[201][201];
int v[201];
int n,k,d,p;
long max=0;

int main()
{
    scanf("%d",&n);

    for( k=0; k<n; k++)
    {
        scanf("%d",&v[k]);
        v[n+k]=v[k];
    }
    for( k=0; k<2*n; k++)
        f[k][k]=0;

    for( d=1; d<n; d++)
    {
        for( k=0; k<2*n; k++)
        {
            int j=k+d;
            if(j<2*n)
            {
                for( p=k; p<j; p++)
                {
                    if(f[k][j]<f[k][p]+f[p+1][j]+v[k]*v[p+1]*v[j+1])
                        f[k][j]=f[k][p]+f[p+1][j]+v[k]*v[p+1]*v[j+1];
                }
            }
        }
    }

    for(k=0; k<n; k++)
    {
        if(max<f[k][k+n-1])max=f[k][k+n-1];
    }
    printf("%ld\n",max);

    return 0;
}
