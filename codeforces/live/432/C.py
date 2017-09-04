import math

def dotproduct(v1, v2):
    return sum((a*b) for a, b in zip(v1, v2))

def norm(v):
    return math.sqrt(dotproduct(v, v))

def angle(v1, v2):
    return math.degrees(math.acos(dotproduct(v1, v2) / (norm(v1) * norm(v2))))

def all_good(p, i):
    for j in range(len(p)):
        if norm(p[i]) * norm(p[j]) == 0:
            continue
        if i != j and angle(p[i], p[j]) < 90:
            return False
    return True

n = int(input())
points = [list(map(int, input().strip().split())) for _ in range(n)]
cnt = []
for i in range(n):
    if all_good(points, i):
        print(i)
        cnt.append(i)
print(len(cnt))
if cnt:
    print('\n'.join([str(i+1) for i in cnt]))

