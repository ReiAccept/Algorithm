#include <cstdio>

#define MOD 10000

int t,n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%lld\n", (long long)n * n % MOD);
    }
    return 0;
}
