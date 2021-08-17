#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;

int i, j, n;
char c[10000009];
int main()
{
    while(cin >> (c + 1))
    {
        n = strlen(c + 1);
        if(!(n & 1) || c[(n + 1) / 2] != '&' )
        {
            printf("NO\n");
            continue;
        }
        int f = 1;
        i = 1;
        j = n;
        while(i != j)
        {
            if(c[i] != c[j])
            {
                f = 0;
                break;
            }
            i++;
            j--;
        }
        printf("%s\n", f ? "YES": "NO");


    }
    return 0;
}

