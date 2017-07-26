from math import factorial
from multiprocessing.dummy import Pool as ThreadPool

pool = ThreadPool(8)
limit = 1000000
fact = dict()

def digit_factorial(n):
    if n not in fact:
        fact[n] = sum(factorial(int(c)) for c in str(n))
    return fact[n]

def chain_size(n, chain = None):
    if not chain:
        chain = set()
    elif n in chain:
        return 0
    chain.add(n)
    sig = digit_factorial(n)
    return chain_size(sig, chain) + 1

def length_of_60(n):
    if chain_size(n) == 60:
        return 1
    else:
        return 0

count = pool.map(length_of_60, range(1, limit))
print(sum(count))
