#include <bits/stdc++.h>
#define ll long long
using namespace std;

int k;
int len[6];
ll dp[31][16][11][8][7];

ll dfs(int a,int b,int c,int d,int e)
{
    if(a<0||b<0||c<0||d<0||e<0)return 0;
    ll &opt=dp[a][b][c][d][e];
    if(opt)return opt;
    opt=dfs(a,b,c,d,e-1);
    if(d>e)opt+=dfs(a,b,c,d-1,e);
    if(c>d)opt+=dfs(a,b,c-1,d,e);
    if(b>c)opt+=dfs(a,b-1,c,d,e);
    if(a>b)opt+=dfs(a-1,b,c,d,e);
    return opt;
}

int main()
{
    while(scanf("%d",&k) && k)
    {
        memset(len,0,sizeof(len));
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0][0]=1;
        for(int i=1; i<=k; i++) scanf("%d",len+i);
        printf("%lld\n",dfs(len[1],len[2],len[3],len[4],len[5]));
    }
    return 0;
}

