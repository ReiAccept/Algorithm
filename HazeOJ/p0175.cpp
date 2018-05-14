#include<cstdio>

using namespace std;

int minn(int x, int y)
{
    int z = y;
    while(x%y!=0)
    {
        z = x%y;
        x = y;
        y = z;
    }
    return z;
}

int main()
{
    int n,m,k;
    scanf("%d%d",&n,&m);
    k=minn(n,m);
    printf("%d",m-k);
}
