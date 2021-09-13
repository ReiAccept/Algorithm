#include<cstdio>
#include<algorithm>

using namespace std;

int n,c,s,dp[20],p[20],dd[20];

int main()
{
    while(scanf("%d",&p[n])!=EOF) ++n;
    for(int i=0; i<n; ++i)
        dd[i]=dp[i]=1;
    for(int i=0; i<n; ++i)
        for (int j=i-1; j>=0; --j)
            if(p[i]<=p[j])
                dp[i]=max(dp[i],dp[j]+1);
            else
                dd[i]=max(dd[i],dd[j]+1);
    for(int i=0; i<n; ++i)
    {
        c=max(c,dp[i]);
        s=max(s,dd[i]);
    }
    printf("%d\n%d",c,s);
    return 0;
}
