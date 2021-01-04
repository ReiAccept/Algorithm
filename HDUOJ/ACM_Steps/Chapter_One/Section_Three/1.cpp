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

int n;
int a[1003], b[1003];

void work()
{
    while (n = read())
    {
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            b[i] = read();
        sort(a + 1, a + 1 + n, [](int x, int y) { return x > y; });
        sort(b + 1, b + 1 + n, [](int x, int y) { return x > y; });
        int ji = 0, i = 1, j = 1, sum = 0, k = n, f = n;
        while (ji < n)
        {
            if (b[j] > a[i])
            {
                sum -= 200;
                j++;
                k--;
                ji++;
                continue;
            } //如果king的比tian的快马快 用tian的慢马对king的快马
            if (b[j] == a[i])
            { //如果相等
                if (b[f] < a[k])
                {
                    f--;
                    k--;
                    sum += 200;
                    ji++;
                    continue;
                } //看两人的慢马 tian的慢马比king的慢马快则比
                if (b[j] > a[k])
                {
                    sum -= 200;
                    k--;
                    j++;
                    ji++;
                }
                else
                {
                    k--;
                    j++;
                    ji++;
                }
                continue;
            }
            if (b[j] < a[i])
            {
                sum += 200;
                j++;
                i++;
                ji++;
                continue;
            } //如果tian的比king的快马快 直接比
        }
        cout << sum << endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T = 1; //read();
    for (int Case = 1; Case <= T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
