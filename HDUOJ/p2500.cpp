#include<cstdio>
#include<cstring>

using namespace std;

int t,n;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n*3; i++)
        {
            for(int j=0; j<n; j++) printf("HDU");
            printf("\n");
        }
    }
    return 0;
}
