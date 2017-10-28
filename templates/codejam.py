import sys
filename = 'A'
fin = open(f'{filename}.in', 'r')
fout = open(f'{filename}.out', 'w')

T = int(fin.readline())
for tt in range(T):
    N = int(fin.readline())
    res = 0

    fout.write(f'Case #{tt+1}: {res}')
