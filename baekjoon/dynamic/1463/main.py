op = [0 for n in range(1000001)]
oo = 0x3f3f3f3f

def MIN(a, b):
    return a if b>a else b

if __name__=='__main__':
    n = int(input())
    ret = oo
    op[1] = 0
    op[2] = 1
    op[3] = 1
    for i in range(4,n+1):
        ret = oo
        if i%3==0:
            ret = MIN(ret, op[int(i/3)]+1)
        if i%2==0:
            ret = MIN(ret, op[int(i/2)]+1)
        ret = MIN(ret, int(op[i-1]+1))
        op[i] = ret
        
    print("%d" %(op[n]))
    