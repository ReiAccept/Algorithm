#include<cstdio>
#include<algorithm>

using namespace std;

int v,n;
int a[33],f[20003];

int main()
{
    scanf("%d%d",&v,&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=v;j>=a[i];j--)
            f[j]=max(f[j-a[i]]+a[i],f[j]);
    printf("%d\n",v-f[v]);
    return 0;
}
