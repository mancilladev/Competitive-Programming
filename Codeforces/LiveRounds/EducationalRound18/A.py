n = int(input())
a = sorted(int(x) for x in input().split())
md = 9999999999
cnt = 0
for x, y in zip(a, a[1:]):
    if y-x < md:
        cnt = 1
        md = y-x
    elif y-x == md:
        cnt += 1
print(md, cnt)
