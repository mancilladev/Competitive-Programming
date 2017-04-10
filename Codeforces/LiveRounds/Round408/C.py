N = int(input().strip())
computers = {i+1: int(val) for i, val in enumerate(input().strip().split())}
neigh = dict()

for i in range(N-1):
    a, b = map(int, input().strip().split())

    if a in neigh:
        neigh[a].append(b)
    else:
        neigh[a] = [b]

    if b in neigh:
        neigh[b].append(a)
    else:
        neigh[b] = [a]

while len(computers):
    max(computers)
