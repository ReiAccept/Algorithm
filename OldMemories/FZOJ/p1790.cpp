#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,k,cm,ans;
int a[201],b[201],c[101];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
                swap(b[j],b[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(c[b[i]])
        {
            ans+=a[i];
            c[b[i]]--;
            cm++;
            if(cm==m)
                break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
