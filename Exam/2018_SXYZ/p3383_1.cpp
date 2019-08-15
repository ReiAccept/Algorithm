#include<cmath>
#include<cstdio>

using namespace std;

int n,m;

bool is_prime(int a)
{
    if(a==2||a==3)
        return true;
    if(a==1 || (a%6!=1 && a%6!=5))
        return false;
    int temp=sqrt(a);
    for(int i=5;i<=temp;i+=6)
    {
        if(a%i==0||a%(i+2)==0)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if(is_prime(x))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
