from collections import deque

with open('input.txt', 'r') as input:
    n = int(input.readline())
    res = []
    mean = 0
    cnt = dict()
    dq = deque()
    for i in range(n):
        s = input.readline()
        if s[0] == '+':
            cur = int(s.split(' ')[1])
            mean = (mean*len(dq) + cur) / (len(dq) + 1)
            cnt[cur] = cnt.get(cur, 0) + 1
            dq.append(cur)
        elif s[0] == '?':
            if int(mean) == mean:
                res.append(cnt[int(mean)])
            else:
                res.append(0)
        elif s[0] == '-':
            mean = (mean*len(dq) - dq[0]) / (len(dq) - 1)
            cnt[dq[0]] -= 1
            dq.popleft()


with open('output.txt', 'w') as output:
    output.write('\n'.join(str(x) for x in res))
    output.write('\n')

