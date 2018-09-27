#include<cstdio>
#include<algorithm>

using namespace std;

int n,ans;
int a[100003],b[100003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        int tmp=abs(a[i]-b[i]);
        if(tmp==0)
            ans--;
        else
            ans+=tmp;
    }
    printf("%d\n",ans);
    return 0;
}
