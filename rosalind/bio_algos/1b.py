from sys import stdin
lines = stdin.readlines()

from ba1a import PatternCount

def n_wise(it, n):
    it = iter(it)
    while True:
        yield [next(it) for i in range(n)]

def FrequentWords(text, k):
    patterns = set(text[i:i+k] for i in range(len(text) - k + 1))
    best_count = 0
    count = dict()
    for pattern in patterns:
        count[pattern] = PatternCount(text, pattern)
        best_count = max(best_count, count[pattern])
    return [pattern for pattern in patterns if count[pattern] == best_count], best_count

for text, k in n_wise(lines, 2):
    text = text.strip()
    k = int(k.strip())
    res, c = FrequentWords(text, k)
    print(c, ' '.join(res))
