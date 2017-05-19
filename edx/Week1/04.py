with open('input.txt', 'r') as input:
    a = [int(x) for x in input.readline().split()]
    b = [int(x) for x in input.readline().split()]
    c = [int(x) for x in input.readline().split()]

dist = lambda x, y, z: (x*x + y*y + z*z)**0.5

ans = 0
perms = __import__('itertools').permutations([0,1,2])
for i, j, k in perms:
    ans = max(ans, dist(a[i], b[j], c[k]))

with open('output.txt', 'w') as output:
    output.write(str(ans))
    output.write('\n')

