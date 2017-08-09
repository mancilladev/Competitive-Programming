import numpy as np
M = np.loadtxt('file_081.txt', delimiter=',')
print(M)
print(len(M), len(M[0]))

INF = sum(sum(M))
for y in range(len(M)):
    for x in range(len(M[0])):
        if y == x == 0:
            continue
        top = INF if y == 0 else M[y-1][x]
        left = INF if x == 0 else M[y][x-1]
        M[y][x] += min(top, left)
print(M[-1][-1])
