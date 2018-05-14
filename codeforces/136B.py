def untor(a, c):
    res = ''
    while a or c:
        a, ma = divmod(a, 3)
        c, mc = divmod(c, 3)
        x = 0
        while (ma + x)%3 != mc:
            x += 1
        res = str(x) + res
    try:
        return int(res, 3)
    except Exception as e:
        return 0

a, c = map(int, input().split())
print(untor(a, c))
