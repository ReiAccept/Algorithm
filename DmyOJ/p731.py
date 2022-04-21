replaces = {}

q = int(input())
requests = [input() for i in range(q)]

ans = []
for r in requests[::-1]:
  if r[0] == '1':
    v = int(r[2:])
    ans.append(replaces.get(v, v))
  else:
    u, w = map(int, r[2:].split())
    replaces[u] = replaces.get(w, w)
print(*ans[::-1])

# CF AC but DmyOJ TLE2