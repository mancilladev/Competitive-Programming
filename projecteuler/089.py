saved = 0
with open('file_089.txt', 'r') as fin:
    for line in fin:
        a = line.strip()
        b = a
        b = b.replace('DD', 'M')
        b = b.replace('DCCCC', 'CM')

        b = b.replace('CCCCC', 'D')
        b = b.replace('CCCC', 'CD')

        b = b.replace('LL', 'C')
        b = b.replace('LXXXX', 'XC')

        b = b.replace('XXXX', 'XL')

        b = b.replace('VV', 'X')
        b = b.replace('VIIII', 'IX')

        b = b.replace('IIII', 'IV')

        saved += (len(a) - len(b))
print(saved)
