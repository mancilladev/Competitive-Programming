def solve(s):
    _sum = sum(int(c) for c in s)
    remaining = _sum%3
    if remaining == 0:
        return s
    elif str(remaining) in s:
        return ''.join(s.rsplit(str(remaining), 1))


digits = input()
