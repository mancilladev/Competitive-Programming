l1, r1, l2, r2, k = map(int, input().split())
l = max(l1, l2)
r = min(r1, r2)
if l <= k <= r:
    r -= 1
print(max(0, r-l+1))
