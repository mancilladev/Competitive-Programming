n, k, l, c, d, p, nl, np = map(int, input().strip().split())
ans = [k*l//nl, c*d, p//np]
print(min(ans)//n)
