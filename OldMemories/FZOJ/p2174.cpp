#include<cstdio>
#include<algorithm>
 
using namespace std;

int a[100005];
int n,m,l,r,ans=0x3f3f3f3f;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>r)
			r=a[i];
    }
    while(l<=r)
    {
        int k=1,mid=(l+r)/2;
        int maxx=0,minx=0x3f3f3f3f;
        for(int i=1;i<=n;i++)
        {
            minx=min(minx,a[i]);
            maxx=max(maxx,a[i]);
            if((maxx-minx>mid))
               {
                   k++;
                   minx=a[i];
                   maxx=a[i];
               }
            if(k>m)
                break;
        }
        if(k>m)
            l=mid+1;
        else
        {
            ans=min(ans,mid);
            r=mid-1;
        }
 
    }
    printf("%d",ans);
    return 0;
}
