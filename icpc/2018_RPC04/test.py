import random
f = lambda: random.choice('++')
print(''.join(f() for i in range(10**6)))
