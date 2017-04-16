input =  open('input.txt', 'r')
output = open('output.txt', 'w')

N, M, S = map(int, input.readline().split())

dist = [10**15] * (N+1)
neg = [0] * (N+1)
in_g = [0] * (N+1)

dist[S] = 0

graph = dict()
E = []
for i in range(M):
    a, b, c = map(int, input.readline().split())
    if a in graph:
        graph[a].add(b)
    else:
        graph[a] = {b}
    E.append((a, b, c))

def reachable(u):
    in_g[u] = 1
    for v in graph[u]:
        if not in_g[v]:
            reachable(v)

def setNegative(u):
    neg[u] = 1
    for v in graph[u]:
        if in_g[v] and not neg[v]:
            setNegative(v)

def bellmanFord():
    for i in range(N-1):
        for u, v, w in E:
            if in_g[u]:
                dist[v] = min(dist[v], dist[u] + w)

    for u, v, w in E:
        if in_g[u]:
            cur = min(dist[v], dist[u] + w)
            if cur < dist[v]:
                setNegative(v)
            dist[v] = cur

reachable(S)
bellmanFord()

for i in range(1, N+1):
    if not in_g[i]:
        output.write('*')
    elif neg[i]:
        output.write('-')
    else:
        output.write(str(dist[i]))
    output.write('\n')

input.close()
output.close()

