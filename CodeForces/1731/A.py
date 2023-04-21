from math import prod

for _ in range(int(input())):
    n = int(input())
    print(2022*(prod(map(int,input().split()))+n-1))