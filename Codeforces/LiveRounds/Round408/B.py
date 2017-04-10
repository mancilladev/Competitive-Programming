N, M, K = map(int, input().strip().split())
holes = set(int(x) for x in input().strip().split())

pos = 1
if pos not in holes:
    for i in range(K):
        a, b = map(int, input().strip().split())
        if pos == a:
            pos = b
        elif pos == b:
            pos = a
        if pos in holes:
            break

print(pos)

