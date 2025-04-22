MOD, T = 10**9+7, int(input())
for CASE in range(T):
    n, m = map(int, input().split())
    a = 0
    for i in range(m):
        l, r, x = map(int, input().split())
        a = a | x
    print((a * pow(2, n-1, MOD)) % MOD)
