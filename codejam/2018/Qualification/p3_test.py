from random import randint
from collections import Counter
import matplotlib.pyplot as plt

def simulate(n):
    st = set()
    tries = 0
    while len(st) < n:
        x = randint(1, n)
        st.add(x)
        tries += 1
    return tries

tests = 10000
N = 200

'''
N: 20
MAX FREQ: (64, 223)
MEAN: 72.5469
'''

results = [simulate(N) for i in range(tests)]
print('N:', N)
print('MAX FREQ:', max(Counter(results).items(), key=lambda t: t[1]))
print('MEAN:', sum(results) / len(results))

values, freq = zip(*Counter(results).items())
plt.bar(values, freq, 1)
plt.show()
