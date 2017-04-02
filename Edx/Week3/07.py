with open('input.txt', 'r') as input:
    n, k = map(int, input.readline().split())
    l = [None]*n
    for i in range(n):
        v, w = map(int, input.readline().split())
        t = (v, w, i+1)
        l[i] = t

top = 0
bot = 0
ans = [None]*k

for i in range(k):
    v, w, _ = l[0]
    nt = top + v
    nb = bot + w
    pos = 0
    for j in range(1, n-i):
        v, w, _ = l[j]
        pt = top + v
        pb = bot + w
        if pt/pb > nt/nb:
            nt = pt
            nb = pb
            pos = j
    top = nt
    bot = nb
    ans[i] = l[pos]
    l[pos], l[-i-1] = l[-i-1], l[pos]


print('list: ', l)
print('{}/{}'.format(top, bot))
print(' '.join(str(x[2]) for x in ans))

with open('output.txt', 'w') as output:
    output.write(' '.join(str(x[2]) for x in ans))
    output.write('\n')
