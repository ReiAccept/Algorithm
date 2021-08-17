#include <bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define MMST(x, y) memset(x, y, sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF = 0x3f3f3f3f;

int read()
{
    char c;
    int num, f = 1;
    while (c = (char)getchar(), !isdigit(c))
        if (c == '-')
            f = -1;
    num = (int)(c - '0');
    while (c = (char)getchar(), isdigit(c))
        num = num * 10 + (int)(c - '0');
    return num * f;
}
void prt(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        prt(x / 10);
    putchar((char)(x % 10 + '0'));
}

string s;
int l, i, j, k, n;

void work()
{
    getline(cin, s);
    l = s.length();
    for (k = 0, j = -1; k <= l; k++)
    {
        if (s[k] == ' ' || k == l)
        {
            for (i = k - 1; i > j; i--)
                cout << s[i];
            if (k != l)
                cout << ' ';
            else
                cout << endl;
            j = k;
        }
    }
    return;
}

signed main()
{
    int T = read();
    for (int Case = 1; Case <= T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
