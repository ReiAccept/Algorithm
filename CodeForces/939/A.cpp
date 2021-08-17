#include<cstdio>

using namespace std;

int n,a[5001];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[a[a[i]]]==i)
        {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}
