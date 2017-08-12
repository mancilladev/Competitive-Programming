y = lambda x, D: (x**2 - 1)**0.5 / (D)**0.5

def calculate(D):
    for x in range(2, 1000000):
        z = y(x, D)
        if z == int(z):
            return x
    return 0

squares = (x**2 for x in range(int(1000**.5)+1))
res = max(calculate(d) for d in range(100, 1001) if d not in squares)
print(res)

