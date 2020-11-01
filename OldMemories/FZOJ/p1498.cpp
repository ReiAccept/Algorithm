#include<stdio.h>

int n,m;
int map[400]= {0},card[400]= {0},f[41][41][41][41]= {0},count[5];
int
max(int a,int b,int c,int d)
{
    int temp;
    if(a>b)
        temp=a;
    else
        temp=b;
    if(c>temp)
        temp=c;
    if(d>temp)
        temp=d;
    return temp;
}
int main()
{
    int i,j,q,p,a,b,c,d;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&map[i]);
    for(j=1; j<=m; j++)
    {
        scanf("%d",&card[j]);
        count[card[j]]++;
    }
    for(i=0; i<=count[1]; i++)
        for(j=0; j<=count[2]; j++)
            for(q=0; q<=count[3]; q++)
                for(p=0; p<=count[4]; p++)
                {
                    if(i-1<0)
                        a=0;
                    else
                        a=f[i-1][j][q][p];
                    if(j-1<0)
                        b=0;
                    else
                        b=f[i][j-1][q][p];
                    if(q-1<0)
                        c=0;
                    else
                        c=f[i][j][q-1][p];
                    if(p-1<0)
                        d=0;
                    else
                        d=f[i][j][q][p-1];
                    f[i][j][q][p]=max(a,b,c,d)+map[1+1*i+2*j+3*q+4*p];
                }
    printf("%d\n",f[count[1]][count[2]][count[3]][count[4]]);
    return 0;
}
