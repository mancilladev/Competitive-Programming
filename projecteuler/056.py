r = 0
for a in range(10,100):
        for b in range(10, 100):
                r = max(r, sum(int(c) for c in str(a**b)))
print(r)
