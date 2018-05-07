flowers = [int(s) for s in input().split()]

ans = min(flowers)
flowers = [f - ans for f in flowers]

if sum(x%3 for x in flowers) == 4 and ans:
    ans += 1

print(sum(x//3 for x in flowers) + ans)
