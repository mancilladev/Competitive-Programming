a, b = map(int, input().strip().split())

if abs(a-b) < 2 and a+b != 0:
    print('YES')
else:
    print('NO')
