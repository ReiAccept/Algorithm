#include<bits/stdc++.h>

using namespace std;

int n,q;
int a[50005][21],b[50005][21];

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i][0]),b[i][0]=a[i][0];
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]),b[i][j]=min(b[i][j-1],b[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=q;i++)
    {
        int l,r; scanf("%d%d",&l,&r);
        int s=(int)log2(r-l+1);
        printf("%d\n",max(a[l][s],a[r-(1<<s)+1][s])-min(b[l][s],b[r-(1<<s)+1][s]));
    }
    return 0;
}
