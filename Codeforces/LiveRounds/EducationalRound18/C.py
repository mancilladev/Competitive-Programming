from itertools import combinations

num = list(int(x) for x in input())
digpos = list(range(len(num)))

def l():
    for i in range(len(digpos), 0, -1):
        for comb in combinations(digpos, i):
            yield list(comb)

found = False
for position in l():
    n = sum(num[p] for p in position)
    if n%3 == 0:
        print(int(''.join(str(num[p]) for p in position)))
        found = True
        break

if not found:
    print(-1)

