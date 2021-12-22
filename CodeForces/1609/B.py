base = ["a", "b", "c"]


def check(pos):
    if s[pos-2:pos+1] == base or s[pos-1:pos+2] == base or s[pos:pos+3] == base:
        return 1
    return 0


n, q = map(int, input().split())
s = list(input())
ans, cnt = [], 0
for i in range(n):
    if s[i:i+3] == ["a", "b", "c"]:
        cnt += 1
for x in range(q):
    pos, c = input().split()
    pos = int(pos)-1
    initial = check(pos)
    s[pos] = c
    final = check(pos)
    cnt += final-initial
    ans.append(cnt)
print(*ans, sep="\n")
