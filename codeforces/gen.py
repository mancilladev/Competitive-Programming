from random import *
from string import *
import re

# gen...
N = 10
seq = [ randint(2, 2**7) for i in range(N) ]
M = 50
queries = []
for i in range(M):
    l = randint(2, 2*10**9)
    r = randint(l, 2*10**9)
    queries.append(str(l) + ' ' + str(r))

print(N)
print( ' '.join( map(str, seq) ) )
print(M)
print( '\n'.join( map(str, queries) ) )
