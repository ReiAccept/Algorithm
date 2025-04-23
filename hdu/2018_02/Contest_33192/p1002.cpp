#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

int a[100005],b[100005],suma[1000005],sumb[1000005];

int main()
{
    int la,lb,t,n,m,Case;
    long long ans;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%d",&n);
        memset(suma,0,sizeof(suma));
        memset(sumb,0,sizeof(sumb));
        ans=la=lb=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            if(suma[t]==0)
                a[la++]=t;
            suma[t]++;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            if(sumb[t]==0)
                b[lb++]=t;
            sumb[t]++;
        }
        for(int i=0; i<la; i++)
            for(int j=0; j<lb; j++)
                ans+=(long long)suma[a[i]]*sumb[b[j]]*(long long)(sqrt(abs(a[i]-b[j])));
        printf("%lld\n",ans);
    }
    return 0;
}
