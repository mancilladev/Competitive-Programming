from decimal import Decimal, getcontext
from math import sqrt

getcontext().prec = 102

res = 0
for n in range(100):
    if not sqrt(n) % 1 == 0:
        a = str(Decimal(n).sqrt()).replace('.', '')[:100]
        res += sum(map(int, a))
print(res)
