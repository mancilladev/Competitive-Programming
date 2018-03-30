filename = 'C-large-practice'
fin = open(f'{filename}.in', 'r')
fout = open(f'{filename}.out', 'w')

def solve(out):
    print()
    ans = 0
    twocycle = [0] * N
    for i in range(N):
        cur = i
        vis = [0] * N
        vis[cur] = 1
        while vis[out[cur]] == 0:
            vis[out[cur]] = 1
            cur = out[cur]
        if out[cur] == i:
            ans = max(ans, sum(vis))
        if out[out[cur]] == cur:
            twocycle[cur] = max(twocycle[cur], sum(vis))
        # print(i+1, [i+1 for i, v in enumerate(vis) if v])

    tot = 0
    for i in range(N):
        if out[out[i]] == i:
            tot += twocycle[i] + twocycle[out[i]] - 2
    return max(ans, tot // 2)

T = int(fin.readline())
for tt in range(T):
    N = int(fin.readline())
    norm = lambda x: int(x)-1
    out = list(map(norm, fin.readline().split(' ')))

    fout.write(f'Case #{tt+1}: {solve(out)}\n')
