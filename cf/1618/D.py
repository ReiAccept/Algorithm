for _ in range(int(input())):
    n, k = map(int, input().split())
    l = sorted(map(int, input().split()))
    s = sum(l[:n-2*k])
    i, j = n-2*k, n-k
    for x in range(k):
        if l[i] == l[j]:
            s += 1
        i, j = i+1, j+1
    print(s)
