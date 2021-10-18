from multiprocessing import Process

def ok(need):
    l=-5000
    r=5000
    res=-12345678
    while(r-l>0):
        mid=(l+r)/2
        tmp=mid*mid*mid
        if(tmp == need):
            return mid
        if(tmp>need):
            r=mid-1
        else:
            l=mid+1
    return res


def work(x):
    limits = 5000
    a=-limits
    while(a<=limits):
        b=-limits
        while(b<=limits):
            need=x-a*a*a-b*b*b
            c=ok(need)
            if(c<0):
                c=-c
            if(c<-limits):
                print('a['+str(x)+']=' +str(a) + ';')
                print('b['+str(x)+']=' +str(b) + ';')
                print('c['+str(x)+']=' +str(c) + ';')
                print('vis['+str(x)+']=true;')
                return
        i=i+1


def main():
    p_list = []
    for i in range(201):
        # work(i)
        p = Process(target=work, args=(i,))
        p_list.append(p)
    for p in p_list:
        p.start()
        
    for p in p_list:
        p.join()


if __name__ == '__main__':
    main()