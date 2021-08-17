#include <cstdio>

using namespace std;

int n,flag;

int main()
{
    scanf("%d",&n);
    if(n==1)
        printf("\\t");
    for(int i=2; i<n; i++)
        if(n%i==0)
        {
            flag=1;
            break;
        }
    if(flag)
        printf("\\n");
    else
        printf("\\t");
    return 0;
}
