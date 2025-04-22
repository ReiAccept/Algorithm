x, y = map(int, input().split())
s, flag = set([x]), False
for _ in range(25):
    t = set()
    for i in s:
        if i == y:
            flag = True
            break
        a = bin(i)[2:]
        t.add(int(a[::-1], 2))
        a += "1"
        t.add(int(a[::-1], 2))
    if flag:
        break
    s = t
print("YES" if flag else "NO")
