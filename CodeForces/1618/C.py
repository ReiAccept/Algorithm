from math import gcd

for _ in range(int(input())):
    n = int(input())
    l = [int(i) for i in input().split()]
    a = l[0]
    for i in l[::2]:
        a = gcd(a, i)
    if all(i%a for i in l[1::2]):
        print(a)
        continue
    a = l[1]
    for i in l[1::2]:
        a = gcd(a, i)
    if all(i%a for i in l[::2]):
        print(a)
        continue
    print(0)