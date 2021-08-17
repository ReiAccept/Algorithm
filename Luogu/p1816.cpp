#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;
int a[100005][21];

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++) scanf("%d",&a[i][0]);
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=m;i++)
            a[i][j]=min(a[i][j-1],a[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int k=log2(r-l+1);
        printf("%d ",min(a[l][k],a[r-(1<<k)+1][k]));
    }
    return 0;
}
