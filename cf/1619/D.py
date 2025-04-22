for _ in range(int(input())):
    input() # SB
    m, n = list(map(int, input().split()))
    l = []
    maxx = 0
    for i in range(m):
        l.append(list(map(int, input().split())))
        maxx = max(maxx, max(l[-1]))
    lft, rig = 1, maxx+1
    l.sort(reverse=True)
    while lft < rig:
        pos, ct, mid, vis = 0, 0, (lft + rig+1)//2, [0]*n
        for i in range(m):
            ct = 0
            for j in range(n):
                if l[i][j] >= mid:
                    vis[j] = 1
                    ct += 1
            if ct > 1:
                pos = 1
        pos = (sum(vis) == n) and (pos)
        if pos:
            lft = mid
        else:
            rig = mid-1
    print(lft)
