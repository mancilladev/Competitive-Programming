with open('input.txt', 'r') as input:
    n, k = [int(x) for x in input.readline().split(' ')]
    matrix = [[0]*n for x in range(n)]
    for i in range(k):
        y, x = map(int, input.readline().split(' '))
        matrix[y-1][x-1] = 1

ans = 'NO'
stack = []
color = [0]*n

def bfs(v):
    color[v] = 1
    stack.append(v+1)
    for u in range(n):
        if not matrix[v][u]:
            continue
        if color[u] == 0 and bfs(u):
            return True
        if color[u] == 1:
            return True
    color[v] = 2
    stack.pop()
    return False

for i in range(n):
    if color[i] == 0 and bfs(i):
        print(stack)
        ans = 'YES\n' + ' '.join([str(x) for x in stack])
        break

with open('output.txt', 'w') as output:
    output.write(str(ans))
    output.write('\n')

