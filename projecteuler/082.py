import numpy as np

M = np.loadtxt('file_082.txt', delimiter=',')
print(len(M), len(M[0]))


INF = sum(sum(M))
