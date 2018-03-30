from collections import Counter
from itertools import chain

filename = 'B-large-practice'
fin = open(f'{filename}.in', 'r')
fout = open(f'{filename}.out', 'w')

def missing(grid):
    flat = list(chain(*grid))
    count = Counter(flat)
    return sorted(k for k,v in count.items() if v & 1)

def solve(N):
    grid = [
        list(map(int,fin.readline().split())) for x in range(1, 2 * N)
    ]
    ans = missing(grid)
    return ' '.join(map(str,ans))

T = int(fin.readline())
for tt in range(T):
    N = int(fin.readline())
    fout.write(f'Case #{tt+1}: {solve(N)}\n')
