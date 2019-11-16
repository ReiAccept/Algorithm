#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[100003][21];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            a[i][j]=min(a[i][j-1],a[i+(1<<(j-1))][j-1]);
    for(int l=1,r=m;l<=n-m+1 && r<=n;l++,r++)
    {
        int k=(int)log2(r-l+1);
        printf("%d\n",min(a[l][k],a[r-(1<<k)+1][k]));
    }
    return 0;
}
