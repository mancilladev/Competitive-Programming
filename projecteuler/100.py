def sign(x):
    return (x > 0) - (x < 0)

def quadratic(a, b, c):
    temp = -0.5 * (b + sign(b) * (b*b - 4*a*c)**0.5);
    x1 = temp / a;
    x2 = c / temp;
    return max(x1, x2)

def bottom(t):
    return t * (t-1) / 2

def solves(b, t):
    return 2 * b * (b-1) == t * (t-1)

def isInteger(b):
    return int(b) == b

blue = 0
total = 10**12

while not isInteger(blue) or not solves(blue, total):
    total += 1
    blue = quadratic(1, -1, -bottom(total))

print(f'Blue={blue} Total={total}')

