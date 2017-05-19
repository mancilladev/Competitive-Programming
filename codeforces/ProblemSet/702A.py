n = int(input())
l = [int(x) for x in input().split()]

ml = 1
mlt = 1
for i in range(1, n):
    if l[i] > l[i-1]:
        mlt += 1
    else:
        ml = max(ml, mlt)
        mlt = 1

print(max(ml, mlt))
