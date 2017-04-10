import sys
fin = open('in', 'r')
fout = open("out", 'w')

def dfs(graph, v, visited=[]):
    curpath = [v]
    if v not in visited:
        curpath += dfs(graph, graph[v], visited+[v])
    return curpath

def biggestSize(graph):
    print(graph)
    path = dict()
    for k in graph:
        path[k] = dfs(graph, k)
    print(path)
    print()

T = int(fin.readline())
for tt in range(T):
    N = int(fin.readline())
    vals = [int(x) for x in fin.readline().strip().split()]
    graph = dict()
    for i, v in enumerate(vals):
        graph[i+1] = v

    fout.write('Case #{0}: {1}'.format(tt+1, biggestSize(graph)))
