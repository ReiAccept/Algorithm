cnt1,cnt2=0,(1+100)*100/2

for i in range(1,101):
    cnt1+=pow(i,2)

cnt2=pow(cnt2,2)

print(cnt2-cnt1)