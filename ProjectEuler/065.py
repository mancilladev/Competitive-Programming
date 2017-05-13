l = 2
r = 3
for i in range(3,101):
    k = i//3 * 2 if i%3 == 0 else 1
    l, r = r, r*k + l
print('Sum of digits in numerator:', sum(int(c) for c in str(r)))
