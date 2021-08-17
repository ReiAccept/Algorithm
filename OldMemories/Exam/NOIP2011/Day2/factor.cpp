#include<cstdio>

int a,b,k,n,m,ans;
int yhsj[1006][1006];

int main()
{
    freopen("factor.in","r",stdin);
    freopen("factor.out","w",stdout);
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    for(int i=1; i<=k+1; i++)
        yhsj[i][1]=1;
    for(int i=2; i<=k+1; i++)
        yhsj[i][i]=1;
    for(int i=3; i<=k+1; i++)
        for(int j=2; j<i; j++)
            yhsj[i][j]=(yhsj[i-1][j-1]+yhsj[i-1][j])%10007;
    //构建完杨辉三角形,找出a,b为1时的系数
    ans=yhsj[k+1][m+1];
    //乘以a,b,数量为n,m个
    a%=10007;
    b%=10007;
    for(int i=1; i<=n; i++)
        ans=(ans*a)%10007;
    for(int i=1; i<=m; i++)
        ans=(ans*b)%10007;
    printf("%d\n",ans);
    return 0;
}
