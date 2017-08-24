from itertools import combinations

def squared_dist(a, b):
    return (a[0] - b[0])**2 + (a[1] - b[1])**2

def is_right_triangle(p, q):
    origin = (0, 0)
    squares = sorted([squared_dist(origin, p), squared_dist(origin, q), squared_dist(p, q)])
    return (squares[0] + squares[1] == squares[2]) and all([c[0] != c[1] for c in combinations((p, q, origin), 2)])

lim = 51
count = 0

for x1 in range(lim):
    for y1 in range(lim):
        for x2 in range(lim):
            for y2 in range(lim):
                if is_right_triangle((x1, y1), (x2, y2)):
                    # print(f'({x1}, {y1}) => ({x2}, {y2})')
                    count += 1

print(count/2)
