from sys import stdin
lines = stdin.readlines()

complement = {
    'A':'T',
    'T':'A',
    'C':'G',
    'G':'C'
}

def ReverseComplement(text):
    return ''.join(complement[x] for x in text[::-1])

for line in lines:
    line = line.strip()
    print(ReverseComplement(line))
