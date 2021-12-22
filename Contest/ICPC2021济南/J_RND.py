from random import randint

T = int(input())

while(T > 0):
    if randint(1, 2) == 1:
        print('-')
    else:
        print('+')
    T = T-1
