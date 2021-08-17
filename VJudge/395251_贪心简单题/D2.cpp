#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2010;
int a[N],pos[N];
int ans1[N*N>>1],ans2[N*N>>1];
int n,k,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int x;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        pos[x]=i;
    }
    for(int i=1;i<=n;++i)
        a[i]=pos[a[i]];
    for(int i=1;i<=n;++i)
    {
        int j=i;
        while(a[j]!=i)
            ++j;
        while(j!=i)
        {
            int l=j-1;
            while(a[l]<j)
                --l;
            ans+=j-l;
            ++k;
            ans1[k]=l;
            ans2[k]=j;
            swap(a[l],a[j]);
            j=l;
        }
    }
    printf("%d\n%d\n",ans,k);
    for(int i=1;i<=k;++i)
        printf("%d %d\n",ans1[i],ans2[i]);
    return 0;
}
