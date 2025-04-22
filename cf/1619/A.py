def work():
    s=input()
    n=len(s)
    if(n%2==1):
        print("NO")
        return
    i=0
    while i< n//2:
        if s[i]!=s[i+(n//2)]:
            print("NO")
            return
        i=i+1
    print("YES")


for _ in range(int(input())):
    work()
