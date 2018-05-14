#include<cstdio>
#include<algorithm>

using namespace std;

int n,sum;
int a[10010];

void df(int x);

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    df(1);
    df(2);
    for(int i=2; i<=n; i++)
    {
        a[i]+=a[i-1];
        sum+=a[i];
        df(i);
        df(i+1);
    }
    printf("%d\n",sum);
    return 0;
}

void df(int x)
{
    int q=x;
    for(int i=q+1; i<=n; i++)
    {
        if(a[i]<a[q])
            q=i;
    }
    swap(a[x],a[q]);
}
