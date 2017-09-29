import math
try:
    while True:
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        print(math.ceil(sum(arr)/k))
except EOFError:
    pass
