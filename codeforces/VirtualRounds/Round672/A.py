n = int(input())

i = 1
s = ''
while len(s) < n:
    s += str(i)
    i += 1

print(s[n-1])
