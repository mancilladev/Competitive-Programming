vals = {'red': 1, 'yellow': 2, 'green': 3, 'brown': 4, 'blue': 5, 'pink': 6, 'black': 7}
n = int(input())
balls = []
for i in range(n):
    b = input().strip()
    balls.append(b)

if all(b == 'red' for b in balls):
    print(1)
else:
    best = max(vals[b] for b in balls)
    r = balls.count('red')
    print(r * best + sum(vals[b] for b in balls))
