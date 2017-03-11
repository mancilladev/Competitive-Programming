with open('input.txt', 'r') as input:
    a = int(input.readline());
    p = [int(x) for x in input.readline().split()]
    t = [int(x) for x in input.readline().split()]

ans = 0
min_diff = 2000
cntp = 0
cntt = 0

for i in range(a):
    cur = max(p[i], t[i])
    ans += cur
    if cur == p[i]:
        cntp += 1
    else:
        cntt += 1
    min_diff = min(min_diff, abs(p[i] - t[i]))

if min(cntt, cntp) == 0:
    ans -= min_diff

with open('output.txt', 'w') as output:
    output.write(str(ans))
    output.write('\n')

