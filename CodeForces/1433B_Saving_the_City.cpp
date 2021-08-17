#include <bits/stdc++.h>
using namespace std;
int T,a, b;
char s[100010];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        long long ans = 0;
        scanf("%d%d", &a, &b);
        cin>>(s+1);
        int n = strlen(s + 1);
        bool have = false;
        int now = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] != s[i - 1])
            {
                if (s[i] == '1') ans += have ? min(now * b, a) : a, have = true;
                now = 1;
            }
            else now++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

