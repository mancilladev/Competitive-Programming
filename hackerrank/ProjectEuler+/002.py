def fibo(N):
    a, b = 1, 1
    l = []
    while b<N:
        l.append(b)
        a, b = b, a+b
    return l

T = int(input())
for i in range(T):
    N = int(input())
    print(sum(filter(lambda x: x%2==0, fibo(N))))
