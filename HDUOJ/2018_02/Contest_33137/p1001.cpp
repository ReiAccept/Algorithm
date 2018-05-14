#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int Case,n,k,ans;
int a[10003];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    scanf("%d",&Case);
    while(Case--)
    {
        ans=0;
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for(int i=0;i<=k&&a[i]>0;i++)
            ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}
