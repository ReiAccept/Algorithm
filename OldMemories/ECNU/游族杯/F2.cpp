#include <bits/stdc++.h>

using namespace std;

int n,res;
string s[1000003];

signed main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    sort(s+1, s+n+1);
    reverse(s+1, s+n+1);
    for (int i = 1; i <= n; ++i)
        if (s[i].size() >= 4 && s[i].substr(s[i].size()-4) == ".eoj")
        {
            if (s[i-1].size() > s[i].size() && s[i-1].substr(0, s[i].size()) == s[i] && s[i-1][s[i].size()] == '/') continue;
            res++;
        }
    cout<<res<<endl;
    return 0;
}

