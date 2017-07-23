from collections import defaultdict, deque

def find_number_universe(keylog):
    numbers = set()
    for attempt in keylog:
        for num in attempt:
            numbers.add(num)
    return numbers

def connections(attempt):
    l = len(attempt)
    for i in range(l - 1):
        for j in range(i + 1, l):
            yield attempt[i], attempt[j]

def make_number_graph(keylog):
    graph = defaultdict(set)
    for attempt in keylog:
        for a, b in connections(attempt):
            graph[a].add(b)
    return graph

def find_smallest_code(start, graph, number_universe):
    queue = deque([ (start, [start]) ])
    while queue:
        curr, path = queue.popleft()
        vecinos = graph.get(curr, [])
        for vecino in vecinos:
            new_path = path + [vecino]
            if not number_universe - set(new_path):
                return len(new_path), ''.join(new_path)
            queue.append((vecino, new_path))

def solve(keylog):
    number_universe = find_number_universe(keylog)
    graph = make_number_graph(keylog)
    candidates = []
    for vertex in graph:
        code = find_smallest_code(vertex, graph, number_universe)
        if code:
            candidates.append(code)
    return sorted(candidates)[0]

with open('file_079.txt', 'r') as fin:
    keylog = [str(int(num)) for num in fin]
    print(solve(keylog))
