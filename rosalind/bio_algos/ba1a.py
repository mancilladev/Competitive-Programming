from sys import stdin

def n_wise(it, n):
    it = iter(it)
    while True:
        yield [next(it) for i in range(n)]

def PatternCount(text, pattern):
    count = 0
    for i in range(len(text) - len(pattern) + 1):
        if text[i:i+len(pattern)] == pattern:
            count += 1
    return count

lines = stdin.readlines()
for text, pattern in n_wise(lines, 2):
    text = text.strip()
    pattern = pattern.strip()
    print(PatternCount(text, pattern))
