#include<cstdio>

using namespace std;

struct zuobiao
{
    int x,y;
} now;

long long n;
int r,c,xi,xj;
char g[2003][2003];
char fx='s',color='A';

void print()
{
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
            if(g[i][j]==0)
                printf(".");
            else
                printf("%c",g[i][j]);
        printf("\n");
    }
}

void upcolor()
{
    if(color=='Z')
        color='A';
    else
        color++;
}

zuobiao fangxiang(int n)
{
    zuobiao dox;
    if(fx=='s')
    {
        fx='z';
        dox.x=0,dox.y=-n;
    }
    if(fx=='z')
    {
        fx='x';
        dox.x=-n,dox.y=0;
    }
    if(fx=='x')
    {
        fx='y';
        dox.x=0;
        dox.y=n;
    }
    if(fx=='y')
    {
        fx='s';
        dox.x=n;
        dox.y=0;
    }
    return dox;
}

void change(zuobiao sed,zuobiao eed)
{
    while(sed.x!=eed.x)
    {
        g[sed.x][sed.y]=color;
        sed.x++;
    }
    while(sed.y!=eed.y)
    {
        g[sed.x][sed.y]=color;
        sed.y++;
    }
}

int main()
{
    scanf("%d%d%d%d%d",&r,&c,&xi,&xj,&n);
    now.x=xi,now.y=xj;
    for(int i=1; i<=n; i++)
    {
        zuobiao mdzz=fangxiang(n);
        mdzz.x+=now.x;
        mdzz.y+=now.y;
        change(now,mdzz);
        upcolor();
        now.x=mdzz.x;
        now.y=mdzz.y;
    }
    print();
    return 0;
}
