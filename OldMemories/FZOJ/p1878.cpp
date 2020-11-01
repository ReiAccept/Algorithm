#include<cstdio>

using namespace std;

int n,m,k,x,e=10,ans=1;

int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&x);
    while(k>0)
    {
        e%=n;
        if(k%2==1)
            ans=(e*(ans))%n;
        k/=2;
        e=(e*e)%n;
    }
    printf("%d",((m*ans)%n+x)%n);
    return 0;
}
