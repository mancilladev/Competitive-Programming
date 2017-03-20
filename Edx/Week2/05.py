with open('input.txt', 'r') as input:
    n = input.readline()
    l = input.readline().strip().split(' ')

s = []
for v in l:
    if v in '+-*':
        a = s.pop()
        b = s.pop()
        if v == '+':
            s.append(b+a)
        elif v == '-':
            s.append(b-a)
        else:
            s.append(b*a)
    else:
        s.append(int(v))

with open('output.txt', 'w') as output:
    output.write(str(s.pop()))
    output.write('\n')

