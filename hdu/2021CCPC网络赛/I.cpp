#include <bits/stdc++.h>
#define pt(x) cout << x << endl;
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read()
{
    char c;
    int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1;
    num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return f * num;
}
const int N = 2e5 + 1009;
int n;
char c[N];
map<pair<int, int>, int> M;
void work()
{
    M.clear();
    n = read();
    scanf("%s", c + 1);
    int u = 0, d = 0, l = 0, r = 0;
    long long ans = 0;
    M[make_pair(0, 0)] = 1;
    for(int i=1;i<=n;i++)
    {
        u += c[i] == 'U';
        d += c[i] == 'D';
        l += c[i] == 'L';
        r += c[i] == 'R';
        if(M.find(make_pair(d - u, r - l)) != M.end())
            ans += M[make_pair(d - u, r - l)];
        M[make_pair(d - u, r - l)]++;
    }
    printf("%lld\n", ans);
}
signed main()
{
    int Case = read();
    while(Case--) work();
    return 0;
}
