#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

int n,maxn;
int a[203],dp[403][403];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=2;i<=n+1;i++){
        for(int l=1;l+i-1<=2*n;l++){
            int r=l+i-1;
            for(int k=l+1;k<=r-1;k++){
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
                maxn=max(maxn,dp[l][r]);
            }
        }
    }
    printf("%d\n",maxn);
    return 0;
}
