#include<cstdio>
#include<cstring>

using namespace std;

int n,flag,n2;

bool fuck[9900000];

int main()
{
    scanf("%d",&n);
    if(n==2)
        printf("1");
    n2=n/2;
    for(int i=1;i<=n2;i++)
        fuck[i]=true;
    for(int i=3;i<=n;i+=2)
        for(int j=3;i*j<=n;j+=2)
            fuck[i*j/2]=false;
    for(int i=1;i<=n2;i++)
        if(fuck[i])
        flag++;
    printf("%d",flag+1);
}
