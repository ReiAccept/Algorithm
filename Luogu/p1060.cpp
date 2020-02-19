#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;
int v[30],p[20],f[30003];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&v[i],&p[i]);
    for(int i=1;i<=m;i++) p[i]*=v[i];
    for(int i=1;i<=m;i++)
        for(int t=n;t>=v[i];t--)
            f[t]=max(f[t-v[i]]+p[i],f[t]);
    printf("%d\n",f[n]);
    return 0;
}
