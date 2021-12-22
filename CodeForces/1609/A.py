for _ in range(int(input())):
    n, a, c = int(input()), list(map(int, input().split())), 0
    for i in range(n):
        while(a[i] % 2 == 0):
            a[i] = a[i]//2
            c += 1
    a.sort()
    a[-1] = a[-1]*(1 << c)
    print(sum(a))
