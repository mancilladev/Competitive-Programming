from sys import stdin
lines = stdin.readlines()

from ba1a import PatternCount

def n_wise(it, n):
    it = iter(it)
    while True:
        yield [next(it) for i in range(n)]

def FrequentWords(text, k):
    patterns = set(text[i:i+4] for i in range(len(text) - 4 + 1))
    for pattern in patterns:
        count = PatternCount(text, pattern)
        print(pattern, count)
    return patterns

for text, k in n_wise(lines, 2):
    text = text.strip()
    k = int(k.strip())
    print(FrequentWords(text, k))
