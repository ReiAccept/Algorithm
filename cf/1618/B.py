for _ in range(int(input())):
    n = int(input())
    s = input().split()
    r = s[0]
    for i in s[1:]:
        if(r[-1] != i[0]):
            r += i
        else:
            r += i[1]
    if(len(r) != n):
        r += 'a'
    print(r)
