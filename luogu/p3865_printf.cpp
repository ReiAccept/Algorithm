#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int Max[1000005][21];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&Max[i][0]);
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int k=log2(r-l+1);
        printf("%d\n",max(Max[l][k],Max[r-(1<<k)+1][k]));
    }
    return 0;
}
//ST表模板题
//MDZZ洛谷,模板题卡常数,非要加一个快读
