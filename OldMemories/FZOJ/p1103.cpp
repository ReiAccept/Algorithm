#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1],f1[n+1],f2[n+1],i,j,k=0;
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    f1[1]=1;
    f2[n]=1;
    for(i=2; i<=n; i++)
    {
        f1[i]=1;
        for(j=1; j<i; j++)
        {
            if(a[j]<a[i])
                f1[i]=max(f1[i],f1[j]+1);
        }
    }
    for(i=n-1; i>=1; i--)
    {
        f2[i]=1;
        for(j=n; j>i; j--)
        {
            if(a[j]<a[i])
                f2[i]=max(f2[i],f2[j]+1);
        }
    }
    for(i=1; i<=n; i++)
        if(f1[i]+f2[i]>k)
            k=f1[i]+f2[i];
    printf("%d\n",n-k+1);
    return 0;
}
