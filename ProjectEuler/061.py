MIN, MAX = 1000, 9999
K = 6
poly = []
ds = dict()
arr = [None]*K

def calc(n, f):
    if f == 0:
        return n * (n + 1) // 2
    if f == 1:
        return n * n
    if f == 2:
        return n * (3 * n - 1) // 2
    if f == 3:
        return n * (2 * n - 1)
    if f == 4:
        return n * (5 * n - 3) // 2
    return n * (3 * n - 2)

def solves(types, nums):
    if len(types) == K:
        if nums[0]//100 == nums[-1]%100:
            print(nums, sum(nums))
            return True
        else:
            return False
    for t, v in ds:
        if t not in types and nums[-1]%100 == v//100 and solves(types+[t], nums+[v]):
            return True
    return False

def main():
    x =  1
    while calc(x, 0) <= MAX:
        for y in range(K):
            z = calc(x, y)
            if MIN <= z <= MAX:
                poly.append((y, z))
        x += 1

    for t1, v1 in poly:
        for t2, v2 in poly:
            if t1 != t2 and v1%100 == v2//100:
                ds[t1, v1] = ds.get((t1, v1), []) + [(t2, v2)]

    for t, v in ds:
        if solves([t], [v]):
            break

main()
