#include<cstdio>

int huanfang[41][41],n;

struct node
{
    int x,y;
} c[1700];

int main()
{
    scanf("%d",&n);
    huanfang[0][(n-1)/2]=1;
    c[1].x=0;
    c[1].y=(n-1)/2;
    for(int i=2; i<=n*n; i++)
    {
        if(c[i-1].x==0 && c[i-1].y<n-1)
        {
            c[i].x=n-1;
            c[i].y=c[i-1].y+1;
            huanfang[n-1][c[i-1].y+1]=i;
            continue;
        }
        if(c[i-1].y==n-1 && c[i-1].x!=0)
        {
            c[i].x=c[i-1].x-1;
            c[i].y=0;
            huanfang[c[i-1].x-1][0]=i;
            continue;
        }
        if(c[i-1].x==0 && c[i-1].y==n-1)
        {
            c[i].x=1;
            c[i].y=n-1;
            huanfang[1][n-1]=i;
            continue;
        }
        if(!huanfang[c[i-1].x-1][c[i-1].y+1])
        {
            c[i].x=c[i-1].x-1;
            c[i].y=c[i-1].y+1;
            huanfang[c[i-1].x-1][c[i-1].y+1]=i;
            continue;
        }
        c[i].x=c[i-1].x+1;
        c[i].y=c[i-1].y;
        huanfang[c[i-1].x+1][c[i-1].y]=i;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ",huanfang[i][j]);
        printf("\n");
    }
    return 0;
}
