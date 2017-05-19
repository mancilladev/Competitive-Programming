from functools import reduce
import operator
import sys
fin = open('in', 'r')
fout = open("out", 'w')

T = int(fin.readline())
for tt in range(T):
    N = int(fin.readline())
    lines = [None] * (2 * N -1)
    for i in range(2*N-1):
        lines[i] = [x for x in fin.readline().strip().split()]

    matrix = [None] * N


    index, matrix[0] = min(enumerate(lines), key=operator.itemgetter(1))
    lines.pop(index)
    index, matrix[-1] = max(enumerate(lines), key=operator.itemgetter(1))
    lines.pop(index)

    print(lines)
    print(matrix)
    ans = []
    fout.write('Case #{0}: {1}'.format(tt+1, ans))
