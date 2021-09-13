/*
ID: sa128471
PROG: skidesign
LANG: C++
*/
#include<cstdio>
#include<climits>

using namespace std;

int n;
int a[1002];
int big=INT_MIN,small=INT_MAX,ans=INT_MAX;

int main()
{
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<small)
            small=a[i];
        if(a[i]>big)
            big=a[i];
    }
    for(int i=small; i<=big-17; i++)
    {
        int s=0;
        for(int j=1; j<=n; j++)
            if(a[j]<i)
                s+=(i-a[j])*(i-a[j]);
            else if(a[j]>i+17)
                s+=(a[j]-i-17)*(a[j]-i-17);
        if(ans>s)
            ans=s;
    }
    printf("%d\n",ans);
    return 0;
}
