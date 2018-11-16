from sys import stdin
from pprint import pprint

def n_wise(it, n):
    it = iter(it)
    while True:
        yield [next(it) for i in range(n)]

def PatternMatching(pattern, text):
    positions = []
    for i in range(len(text) - len(pattern) + 1):
        if text[i:i+len(pattern)] == pattern:
            positions.append(i)
    return positions

def main():
    lines = stdin.readlines()
    for pattern, text in n_wise(lines, 2):
        pattern = pattern.strip()
        text = text.strip()
        res = PatternMatching(pattern, text)
        print(' '.join(str(x) for x in res))

def group_close_ones(positions):
    groups = []
    for i, p in enumerate(positions):
        for g in groups:
            if abs(g[0] - p) <= 500:
                g.append(p)
                break
        else:
            groups.append([p])
    return groups

def vibrio_cholerae():
    lines = []
    with open('vibrio_cholerae.dna.fa', 'r') as fin:
        lines = fin.readlines()
        text = ''.join(l.strip() for l in lines)
    print('Nucleotides:', len(text))
    positions = PatternMatching('CTTGATCAT', text)
    print('Positions:', len(positions))
    pprint(group_close_ones(positions))

if __name__ == '__main__':
    # main()
    vibrio_cholerae()
