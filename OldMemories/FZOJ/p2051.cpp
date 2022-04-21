//二叉树遍历不如floyd
#include<cstdio>

int a[101][101],b[101];
int x,y,n,i,j,k,ans=1000000;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            a[i][j]=10000;
    for(i=1;i<=n;++i)
    {
        scanf("%d%d%d",&b[i],&x,&y);
        a[x][i]=a[i][x]=1;
        a[y][i]=a[i][y]=1;
    }
    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i) 
			if (i!=k)
            for(j=1;j<=n;++j) 
				if ((i!=j)&&(j!=k))
					if (a[i][k]+a[k][j]<a[i][j])
						a[i][j]=a[i][k]+a[k][j];
    for(i=1;i<=n;++i)
    {
        int tem=0;
        for(j=1;j<=n;++j)
            if (i!=j)
               tem+=a[i][j]*b[j];
        if (tem<ans) ans=tem;
    }
    printf("%d\n",ans);
    return 0;
}
