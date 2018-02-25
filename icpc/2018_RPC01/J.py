code = lambda n: 1/n if n else 2

n = int(input())
l = list(map(int, input().split(' ')))

print(sum(code(x) for x in l))

