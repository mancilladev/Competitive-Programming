with open('input.txt', 'r') as input:
    a, b = [int(x) for x in input.readline().split(' ')]

with open('output.txt', 'w') as output:
    output.write(str(a))
    output.write('\n')

