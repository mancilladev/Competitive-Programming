def solve(n): return int((n*(n+1)/2)**2 - n*(n+1)*(2*n+1)/6)
print('\n'.join(str(solve(int(input()))) for x in range(int(input()))))
