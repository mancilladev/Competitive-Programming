from itertools import permutations

def sieve(limit):
    isp = [1] * limit
    isp[0] = 0
    isp[1] = 0
    for i in range(2, limit):
        if isp[i]:
            for j in range(i*i, limit, i):
                isp[j] = 0
    return [i for i, val in enumerate(isp) if val]

def is_prime(n):
    for i in range(2, int(n**.5)+1):
        if n % i == 0:
            return False
    return True

def concat_tuple(t):
    return int(str(t[0]) + str(t[1]))

def all_prime(group):
    return all( is_prime(concat_tuple(p)) for p in permutations(group, 2) )

def make_chain(chain):
    if len(chain) == 5:
        return chain
    for p in primes:
        if p > chain[-1] and all_prime(chain + [p]):
            new_chain = make_chain(chain + [p])
            if new_chain:
                return new_chain
    return False

primes = sieve(10000)
chain = []
while not chain:
    chain = make_chain([primes.pop(0)])
print(chain, sum(map(int, chain)))
