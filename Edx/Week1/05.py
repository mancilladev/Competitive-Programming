with open('input.txt', 'r') as input:
    l = [int(x) for x in input.readline().split(' ')]

with open('output.txt', 'w') as output:
    output.write(str(sum(l)/6))
    output.write('\n')

