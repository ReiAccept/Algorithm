#include<bits/stdc++.h>
#define int long long

using namespace std;

string s;
int n,m,ans,cur;
const int MOD=19260817;

int solve()
{
    cur++;
    int ret = 0;
    while(s[cur]=='(')ret=(ret+solve())%MOD;
    cur++;
    if(!ret) return 1;
    return (ret*n)%MOD;
}

signed main()
{
    cin>>n>>m>>s;
    while (cur<m) ans=(ans+solve())%MOD;
    cout<<ans<<endl;
    return 0;
}

