#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
ll d[100003],dp[100003][3];

void Solve()
{
    memset(dp,0xcc,sizeof dp);
    n=qrd();
    for(int i=1; i<=n; i++) d[i]=qrd();
    dp[0][0]=0;
    for(int i=1; i<=n; i++)
        if(d[i]>0)
        {
            dp[i][0]=max({dp[i][0],dp[i-1][0]+d[i],dp[i-1][1]+d[i],dp[i-1][2]+d[i]});
            dp[i][1]=max({dp[i][1],dp[i-1][1]-d[i],dp[i-1][2]-d[i]});
            dp[i][2]=max({dp[i][2],dp[i-1][2]+d[i]});
        }
        else
        {
            d[i]=-d[i];
            dp[i][0]=max({dp[i][0],dp[i-1][0]-d[i],dp[i-1][1]-d[i],dp[i-1][2]-d[i]});
            dp[i][1]=max({dp[i][1],dp[i-1][0]-d[i],dp[i-1][1]+d[i],dp[i-1][2]+d[i]});
            dp[i][2]=max({dp[i][2],dp[i-1][1]+d[i],dp[i-1][2]+d[i]});
        }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
