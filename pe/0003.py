n,i,res=600851475143,2,1

while n>2:
    if n%i==0:
        n=n//i
        res=i
    else:
        i+=1
print(res)