#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,maxn;
int h[103];
int df[103][103];

int dfx(int start,int gs)
{
    int ans=0;
    if(gs==0)
        return 0;
    for(int i=0;i<gs;i++)
        ans+=h[start+gs];
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            df[i][j]=dfx(i,j);
            maxn=max(maxn,df[i][j]);
        }
    }
    printf("%d",maxn);
    return 0;
}
