n=int(input())
(sum, b)=(int(x) for x in input().split())
dc=[]
for i in range(n):
    t=input().split()
    dc.append((int(t[0]),int(t[1])))
dc.sort(key=lambda x:x[0]*x[1])
ans=0
for i in dc:
    if sum//i[1] > ans:
        ans=sum//i[1]
    sum*=i[0]
print(ans)