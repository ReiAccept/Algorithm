#include<cstdio>
#include<iostream>

using namespace std;

int n,m,q;
int g[203][203];

int main()
{
    scanf("%d%d",&m,&n);q=(n/2)+1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
    for(int i=m,r=q-2;r>0 && m>=1;r--,i--)g[i][r]=0;
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n;j++)
            g[i][j]+=max(g[i-1][j-1],max(g[i-1][j],g[i-1][j+1]));
    cout<<max(g[m][q-1],max(g[m][q],g[m][q+1]))<<endl;
    return 0;
}
