#include <cstdio>

using namespace std;

int n;
long sum;
int a[105],res,flag;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum=sum/n;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=sum)
            res++;
        flag=a[i]-sum;
        a[i+1]+=flag;
    }
    printf("%d",res);
}
