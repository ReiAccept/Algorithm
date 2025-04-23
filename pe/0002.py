a,b,ans=1,1,0

for i in range(3000):
    c=a+b
    if(c>4000000):
        break
    if(c%2==0):
        ans+=c
    a,b=b,c

print(ans)