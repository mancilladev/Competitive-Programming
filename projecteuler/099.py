from math import log

res = (0, 0) # value, index
i = 0

with open('file_099.txt', 'r') as fin:
    for line in fin:
        i += 1
        base, exponent = map(int, line.strip().split(','))
        n = exponent * log(base) # log_k(x^a) > log_k(b^c) => a*log_k(x) > c*log_k(b)
        if n > res[0]:
            res = (n, i)

print(res[1])
