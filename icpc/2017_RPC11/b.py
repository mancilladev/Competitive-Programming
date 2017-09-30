def solve(N, P, C):
    P.sort()
    C.sort()
    print(P, C)
    res = 0
    for i in range(N):
        cnt = 0
        for j in range(i+1, N):
            if P[i] <= C[j]:
                cnt += 1
        if not res:
            res = cnt
        else:
            res *= cnt
    return res%(10**9+7)

N = int(input())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
print(solve(N, P, C))
