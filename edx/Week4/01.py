with open('input.txt', 'r') as input:
    n, k = [int(x) for x in input.readline().strip().split(' ')]
    graph = dict()
    for i in range(k):
        key, val = map(int, input.readline().strip().split(' '))
        s = graph.get(key, set())
        s.add(val)
        graph[key] = s

ans = 'NO'
stack = []
color = [0]*(n+1)

def dfs(v):
    color[v] = 1
    if v in graph:
        stack.append(v)
        for u in graph[v]:
            if color[u] == 0 and dfs(u):
                return True
            elif color[u] == 1:
                stack.append(u)
                return True
        stack.pop()
    color[v] = 2
    return False

for v in graph:
    stack.clear()
    if color[v] == 0 and dfs(v):
        stack = stack[stack.index(stack[-1]):-1]
        ans = 'YES\n' + ' '.join(str(x) for x in stack)
        break

#print(stack)
#print(ans)

with open('output.txt', 'w') as output:
    output.write(ans)
    output.write('\n')

