T = int(input())
for _ in range(T):
    nums = list(map(int, input().split(' ')))
    res = 0
    start = 0
    top = max(nums)
    for x in nums:
        if x == top:
            res += 1
            start = not start
        elif start:
            res += 1
    print(res)

