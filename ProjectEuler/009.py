MAXN=1001

for a in range(1,MAXN):
    for b in range(a+1,MAXN-a,1):
        c=1000-a-b
        if (a*a)+(b*b)==(c*c):
            print(a*b*c)
            exit(0)