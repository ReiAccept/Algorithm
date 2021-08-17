n=int(input())
c=1
for i in range(n+1):
    if(i!=0):
        c=c*i
    #print(c)
print("{:.9f}".format((c*c)/pow(n,n)))