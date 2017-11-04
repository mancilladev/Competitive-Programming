from random import *
from string import *
import re

# gen...
N = 5000
m = randint(100,1000)
k = N//m
seq = [ randint(0, 10**9) for i in range(N) ]

print(N, m, k)
print( ' '.join( map(str, seq) ) )
