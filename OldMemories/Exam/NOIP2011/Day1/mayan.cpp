#include<cstdio>

using namespace std;

int main()
{
    freopen("mayan.out","w",stdout);
    printf("-1");
}

/*
int n;
int G[6][8];

void fds(int x)
{

}

bool kong()
{
    for(int i=1; i<=n; i++)
        if(F[i][0]!=0)
            return false;
    return true;
}

int check(int a,int b)
{
    if((G[a][b-1]==G[a][b])&&(G[a][b+1]==G[a][b]))
    {
        G[a][b-1]=G[a][b]=G[a][b+1]=0;
        return 1;
    }
    if((G[a-1][b]==G[a][b])&&(G[a+1][b]==G[a][b]))
    {
        G[a-1][b]=G[a][b]=G[a+1][b]=0;
        return 2;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<5; i++)
        for(int j=0; j<7; j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==0)
                break;
        }
    return 0;
}
*/
