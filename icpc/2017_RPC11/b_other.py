def solve(N, P, C):
    past = [c for c in C if c >= P[0]]
    res = len(past)
    for p in P[1:]:
        new = [c for c in C if c >= p]
        print(past, new)
        cnt = len(new)
        if set(new) & set(past):
            cnt -= 1
        res *= cnt
        past = new
    return res%(10**9+7)

N = int(input())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
print(solve(N, P, C))
