#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, i, sum, j, N, n;
    cin >> N;
    while (N--)
    {
        sum = 0;
        cin >> n;
        while (n--)
        {
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        if (N != 0)
        {
            printf("\n");
        }
    }

    return 0;
}