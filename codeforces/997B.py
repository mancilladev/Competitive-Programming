def count(s, g):
    res = 0
    for i in range(len(s)-1):
        if s[i:i+2] == g:
            res += 1
    return res

n = int(input())
s = input()

grams = [s[i:i+2] for i in range(n-1)]

best = 0
ans = grams[0]
for g in grams:
    x = count(s, g)
    if x > best:
        best = x
        ans = g

print(ans)
