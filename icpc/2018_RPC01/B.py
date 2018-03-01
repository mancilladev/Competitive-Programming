import matplotlib.pyplot as plt

n = int(input())
points = []
for i in range(n):
    points.append(list(map(int, input().split(' '))))

x = [p[0] for p in points]
y = [p[1] for p in points]

print(x, y)

plt.plot(x, y, 'b+')
plt.show()
