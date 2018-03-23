def ok(s):
    st = set(s)
    if not 2 <= len(st) <= 4:
        return False
    if len(st) == 2:
        return all(s.count(v) >= 2 for v in st)
    elif len(st) == 3:
        return any(s.count(v) >= 2 for v in st)
    else:
        return True

s = input()

if ok(s):
    print('Yes')
else:
    print('No')
