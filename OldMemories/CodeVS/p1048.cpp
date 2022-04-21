#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

int n,w[103],sigma[103],dp[103][103];

int main ()
{
    scanf ("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&w[i]);
        sigma[i]=sigma[i-1]+w[i];
    }
    for(int i=n-1; i>=1; i--)
        for(int j=i+1; j<=n; j++)
        {
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sigma[j]-sigma[i-1]);
        }
    printf ("%d", dp[1][n]);
    return 0;
}
