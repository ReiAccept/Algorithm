#include<cstdio>

using namespace std;

int T,h,w,t;
int fuck[300][300];

void Print()
{
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            printf("%d",fuck[i][j]);
            if(j!=w)
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&h,&w,&t);
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
            {
                scanf("%d",&fuck[i][j]);
                if(fuck[i][j]>=t)
                    fuck[i][j]=255;
                else
                    fuck[i][j]=0;
            }
        Print();
    }
    return 0;
}
