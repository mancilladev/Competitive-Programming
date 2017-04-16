import re

def convert(n):
    z = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    s = ''
    n = int(n)
    while n > 0:
        if n%26==0:
            n = n//26 - 1
            s += 'Z'
        else:
            s += z[n%26-1]
            n //= 26
    return s[::-1]

def sconvert(s):
    z = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    i = 0
    for c in s:
        k = z.index(c) + 1
        i = i*26 + k
    return i

n = int(input())
for i in range(n):
    s = input()
    regex1 = r'R(\d+)C(\d+)'
    match1 = re.search(regex1, s)
    regex2 = r'([A-Z]+)(\d+)'
    match2 = re.search(regex2, s)
    if match1:
        print(convert(match1.group(2)) + match1.group(1))
    else:
        print('R{}C{}'.format(match2.group(2), sconvert(match2.group(1))))
