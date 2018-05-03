from math import cos, sin, radians, pi

sqrt2 = 2**0.5

def matmult(a,b):
    zip_b = list(zip(*b))
    return [[sum(ele_a*ele_b for ele_a, ele_b in zip(row_a, col_b))
             for col_b in zip_b] for row_a in a]

def area(deg1, deg2):
    a = radians(deg1)
    b = radians(deg2)
    return sin(a) + sqrt2 * cos(a) * cos(b - pi/4)

def R(deg1, deg2):
    a = radians(deg1)
    b = radians(deg2)
    rx = [
        [1,0,0],
        [0,cos(a),-sin(a)],
        [0,sin(a),cos(a)]
    ]
    ry = [
        [cos(b),0,sin(b)],
        [0,1,0],
        [-sin(b),0,cos(b)]
    ]
    m = matmult(rx, ry)
    return [[x/2 for x in r][::-1] for r in m][::-1]

T = int(input())
for t in range(1, T+1):
    A = float(input())
    k = 45//2
    deg1, deg2 = 0, 0
    for i in range(100):
        while abs(area(k + deg1, deg2) - A) < abs(area(deg1, deg2) - A):
            deg1 += k
        k /= 2
    k = 45
    for i in range(100):
        while abs(area(deg1, k + deg2) - A) < abs(area(deg1, deg2) - A):
            deg2 += k
        k /= 2
    print('Case #{0}:'.format(t))
    for face in R(deg1, deg2):
        print(' '.join(map(str, face)))
