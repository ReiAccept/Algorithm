ans=-1

def chk(num):
    s=str(num)
    cnt=1
    for c in s:
        if(s[-cnt]!=c):
            return False
        cnt+=1
    return True

for a in range(100,999,1):
    for b in range(100,999,1):
        if(chk(a*b)):
            ans=max(ans,a*b)

print(ans)