s = list(input())

res = []
for i in range(len(s)):
    p = None
    for j in range(i+1, len(s)):
        if s[j] < s[i] and (p == None or s[j] < s[p]):
            p = j
    if p != None:
        s[i], s[p] = s[p], s[i]
        res.append((i+1, p+1))

print('\n'.join('{} {}'.format(t[1], t[0]) for t in res[::-1]))
