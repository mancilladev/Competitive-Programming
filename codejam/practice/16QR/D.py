filename = 'D'
fin = open(f'{filename}.in', 'r')
fout = open(f'{filename}.out', 'w')

def solve(K, C, S):
    if C * S < K:
        return 'IMPOSSIBLE'
    cur = 0
    ans = [0] * S
    for i in range(S):
        if cur == K - 1 and K > 1 and ans[i-1] % K == K - 1:
            S = i
            break
        for j in range(C):
            ans[i] *= K
            ans[i] += cur
            if cur < K - 1:
                cur += 1
        print(i, ans, cur)
    norm = lambda n : str(n + 1)
    return ' '.join(map(norm, ans[:S]))

T = int(fin.readline())
for tt in range(T):
    K, C, S = map(int, fin.readline().split(' '))
    fout.write(f'Case #{tt+1}: {solve(K, C, S)}\n')
