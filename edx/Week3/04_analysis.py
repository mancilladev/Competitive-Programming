A = 2
B = 3
C = 5

def f(a):
    if a == 1: return 1;
    if a == 2: return 2;
    return A*f(a-2) + B*f(a-1) + C

print([f(x) for x in range(3, 5)])
