from random import *

N = 5000
seq = [ randint(1, 10**4) for i in range(N) ]

print(N)
print( ' '.join( map(str, seq) ) )
