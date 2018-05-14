#include<stdio.h>

int n,flag,n2,i,j;

short fuck[9900000];

int main()
{
    scanf("%d",&n);
    n2=n/2;
    for(i=1;i<=n2;i++)
        fuck[i]=1;
    for(i=3;i<=n;i+=2)
        for(j=3;i*j<=n;j+=2)
            fuck[i*j/2]=0;
    for(i=1;i<=n2;i++)
        if(fuck[i])
        flag++;
    printf("%d",flag+1);
    return 0;
}
