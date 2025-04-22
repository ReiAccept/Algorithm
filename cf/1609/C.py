prime = [1]*(1000000+1)
prime[1] = 0


for i in range(2, int(1000000**0.5+1)):
    if prime[i]:
        for j in range(i+i, 1000001, i):
            prime[j] = 0

for _ in range(int(input())):
    n, e = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(e):
        idx, pre, now, pp = i, 0, 0, 0
        while idx < n:
            if a[idx] == 1:
                now += 1
            else:
                if prime[a[idx]]:
                    if pp:
                        ans += (pre+1)*(now+1)-1
                        pre = now
                    else:
                        pre = now
                    now, pp = 0, 1
                else:
                    if pp:
                        ans += (pre+1)*(now+1)-1
                    pre, now, pp = 0, 0, 0
            idx += e
        if pp:
            ans += (pre+1)*(now+1)-1
    print(ans)
