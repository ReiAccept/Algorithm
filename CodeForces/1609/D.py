n, d = map(int, input().split())
fa, remain = [-1]*(n+1), 0


def find(a):
    if fa[a] < 0:
        return a
    fa[a] = find(fa[a])
    return fa[a]


def merge(a, b):
    a, b = find(a), find(b)
    if a == b:
        return 1
    fa[a] += fa[b]
    fa[b] = a
    return 0


for _ in range(d):
    x, y = map(int, input().split())
    remain += merge(x, y)
    ans = 0
    b = sorted(fa)
    for i in range(remain+1):
        if b[i] < 0:
            ans += b[i]
    print(-ans-1)
