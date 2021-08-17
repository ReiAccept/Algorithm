#include<cstdio>
 
using namespace std;

int n;
int f[1003];
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
            f[i]+=f[j];
        f[i]++;
    }
    printf("%d",f[n]%1000000007);
    return 0;
}
