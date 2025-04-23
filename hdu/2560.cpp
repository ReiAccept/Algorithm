#include <cstdio>

using namespace std;

int t,n,m,count,index;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        count = 0;
        for(int i = 1; i <= n * m; i++)
        {
            scanf("%d", &index);
            if ( index ) count++;
        }
        printf("%d\n", count);
    }
}
