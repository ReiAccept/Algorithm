#include <bits/stdc++.h>

using namespace std;

typedef long double rld;
const int INF=-1e9;

int read(){char c;int num, f = 1;while(c = getchar(),!isdigit(c)) if(c == '-') f = -1;num = c - '0';while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';return f * num;}

vector<int> ans;
rld dp[100003][10];
int n, d, a[100003];

int main()
{
    n=read();d=read();
    for(int i=0;i<n;i++) a[i]=read();
    for(int j=0;j<10;j++) dp[n][j]=(j==d)?0:INF;
    for(int i=n-1;i>=0;i--)
        for(int j=0;j<10;j++)
            dp[i][j]=max((rld)INF,max(dp[i+1][(j * a[i]) % 10] + log(a[i]),dp[i+1][j]));
    int i = 0, j = 1;
    while(i!=n)
    {
        if(dp[i+1][(j*a[i])%10]+log(a[i])>=dp[i+1][j])
        {
            ans.push_back(i);
            j=j*a[i++]%10;
        }
        else i++;
    }
    if(j!=d || ans.empty()) cout<<-1<<endl;
    else
    {
        cout<<ans.size()<<endl;
        for(int x: ans) cout<<a[x]<<" ";
    }
    return 0;
}
