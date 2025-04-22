for _ in range(int(input())):
    n = int(input())
    b = list(map(int, input().split()))
    s, t = sum(b), n*(n+1)//2
    if s % t:
        print("NO")
        continue
    s //= t
    f, a = 1, [0]*n
    for i in range(n):
        t = b[i]-b[(i-1) % n]
        if s-t > 0 and (s-t) % n == 0:
            a[i] = (s-t)//n
        else:
            f = 0
            break
    if f:
        print("YES")
        print(*a)
    else:
        print("NO")
