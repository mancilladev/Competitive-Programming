filename = 'A'
fin = open(f'{filename}.in', 'r')
fout = open(f'{filename}.out', 'w')

def solve(N):
    return N

T = int(fin.readline())
for tt in range(T):
    N = map(int, fin.readline().split(' '))
    fout.write(f'Case #{tt+1}: {solve(N)}\n')
