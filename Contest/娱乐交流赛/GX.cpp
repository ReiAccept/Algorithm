#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;
int t;
LL n;
int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%lld",&n);
        LL p=sqrt(n);
        if(p*p==n)
        {
            printf("%lld 1",p);
        }
        else
        {
            if(n==p*(p+1)+1)
            {
                printf("%lld %lld",p+1,p+1);
            }
            else
            {
                if(n<p*(p+1)+1)
                {
                    printf("%lld %lld",n-(p*p+1)+1,p+1);
                }
                else
                {
                    printf("%lld %lld",p+1,(p+1)*(p+1)-n+1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
