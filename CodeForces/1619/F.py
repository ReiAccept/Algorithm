for _ in range(int(input())):
    n, m, k = map(int, input().split())
    st = 1
    for i in range(k):
        tt, rem, nxt = n//m, n % m, st
        for j in range(m):
            print(str(tt+1 if rem else tt)+" ")
            for k in range(tt):
                print(str(st)+" ")
                st += 1
                if st == n+1:
                    st = 1
            if rem:
                rem -= 1
                print(str(st)+" ")
                st += 1
                if st == n+1:
                    st = 1
                if rem == 0:
                    nxt = st
            print("\n")
        st = nxt
    print("\n")
