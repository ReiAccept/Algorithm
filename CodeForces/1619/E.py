from collections import Counter

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    ctr = Counter(l)
    an = [-1]*(n+1)
    take, prev = [], 0
    for i in range(n+1):
        cur = ctr[i]
        an[i] = prev+cur
        if i > 0 and ctr[i-1] == 0:
            if not take:
                an[i] = -1
                break
            x = take.pop()
            prev += (i-1-x)
            an[i] += (i-1-x)
            ctr[i-1] += 1
        if cur > 1:
            take += [i]*(cur-1)
    print(*an)
