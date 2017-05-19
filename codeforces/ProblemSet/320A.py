n = input()
l = ['144', '14', '1']

y = len(n)
for i in range(y):
    for t in l:
        if n.startswith(t):
            n = n.replace(t, '', 1)
            break

if n:
    print('NO')
else:
    print('YES')
