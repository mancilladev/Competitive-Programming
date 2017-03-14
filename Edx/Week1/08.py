with open('input.txt', 'r') as input:
    n = int(input.readline())
    l = sorted(int(x) for x in input.readline().split(' '))

cnt = 0
left = 300*60
for time in l:
    if time > left:
        break
    cnt += 1
    left -= time

with open('output.txt', 'w') as output:
    output.write(str(cnt))
    output.write('\n')

