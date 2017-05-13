import math
n = int(input())
t = math.ceil(math.log10(n+1))
pot = [10**i for i in range(t)][::-1]

res = []
while n:
    a = 0
    for p in pot:
        if n-p >= 0:
            a += p
            n -= p
    res.append(str(a))

print(len(res))
print(' '.join(res))
