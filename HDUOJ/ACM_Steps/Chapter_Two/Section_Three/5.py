import math

def comb(n,m):
    return math.factorial(n)//(math.factorial(n-m)*math.factorial(m))

def main():
    while True:
        try:
            s=int(input())
        except:
            break
        print(comb(2*s,s)//(s+1))

main()

#我真的不想用CPP写高精度啊