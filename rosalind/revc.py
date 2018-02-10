def complement(c):
    if c in 'AT':
        return 'TA'['AT'.find(c)]
    if c in 'CG':
        return 'GC'['CG'.find(c)]

s = input()
res = ''.join(complement(c) for c in s[::-1])
print(res)
