import re


def dist(cur, prev):
    return max(abs(kb[cur][0]-kb[prev][0]),abs(kb[cur][1]-kb[prev][1]))

def code_time(s):
    s = re.sub('\s', '', s)
    t = 0
    for i in range(1, len(s)):
        t += dist(s[i], s[i-1])
    return t


with open('input.txt', 'r') as input:
    w, h = map(int, input.readline().split(' '))

    # Save every char in dictionary as char -> pos
    kb = dict()
    for y in range(h):
        line = input.readline().strip()
        for x in range(w):
            kb[line[x]] = x, y

    use, mintime = None, 10**100
    for i in range(3):
        lang = input.readline()
        _  = input.readline()
        code = ''
        while True:
            code_line = input.readline().strip()
            if code_line == '%TEMPLATE-END%':
                break
            code += code_line
        t = code_time(code)
        if t < mintime:
            use, mintime = lang, t

with open('output.txt', 'w') as output:
    output.write(use)
    output.write(str(mintime))
    output.write('\n')

