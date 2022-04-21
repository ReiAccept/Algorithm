#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int a[20][20];

int maxxx(int n)
{
    int i;
    while (n)
    {
        i = n % 10;
        n = n / 10;
    }
    return i;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        int x=i%10;
        y = maxxx(i);
        a[y][x]++;
    }
    int ans = 0;
    for(int i = 1; i < 10; i++)
        for(int j = 1; j < 10; j++)
            ans = ans + a[i][j] * a[j][i];
    cout << ans << endl;
    return 0;
}

