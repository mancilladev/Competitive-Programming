import numpy as np

M = np.loadtxt('file_082.txt', delimiter=' ', dtype=int)
INF = sum(sum(l) for l in M)
print(INF)
print(M)

#np.savetxt('file_082.txt', M, delimiter=' ', fmt='%i')
