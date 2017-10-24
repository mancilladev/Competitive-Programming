from math import factorial as f

def C(n, k):
    return f(n)//f(k)//f(n-k)

def formato(arr):
    res = []
    for c, a, b in arr:
        s = ''
        if c > 1:
            s += str(c)
        if a:
            s += 'x'
            if a > 1:
                s += '^' + str(a)
        if b:
            s += 'y'
            if b > 1:
                s += '^' + str(b)
        res.append(s)
    return '+'.join(res)

def sol(n):
    return [(C(n,i), n-i, i) for i in range(n+1)]

T = int(input())
for tt in range(T):
    N = int(input())
    if N == 0:
        print(1)
    else:
        print(formato(sol(N)))
