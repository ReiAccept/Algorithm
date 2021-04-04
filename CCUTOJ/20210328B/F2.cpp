#include <bits/stdc++.h>

using namespace std;

int n;
int a[105], cnt[2], loc[2];

signed main() 
{
    ios::sync_with_stdio(false);
    while (cin>>n) 
    {
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; i++) cin>>a[i];
        for (int i = 0; i < n; i++) 
        {
            cnt[a[i]%2]++;
            loc[a[i]%2]=arr[i];
        }
        if (cnt[0] == 1) printf("%d\n", loc[0]);
        else printf("%d\n", loc[1]);
    }
    return 0;
}
