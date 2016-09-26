import itertools


numbers = sorted([''.join(x) for x in itertools.permutations('0123456789')])
print(numbers[999999:1000001])
