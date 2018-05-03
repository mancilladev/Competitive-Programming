def gauss(n):
    return n * (n + 1) / 2

def triangular(count):
    x = 1
    while gauss(x) < count:
        x += 1
    return x if gauss(x) == count else -1

T = int(input())

for t in range(T):
    n = int(input())
    print(triangular(n))
