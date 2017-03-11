T, S, q = map(int, input().split())

r = 0
while S < T:
    r += 1
    S *= q

print(r)