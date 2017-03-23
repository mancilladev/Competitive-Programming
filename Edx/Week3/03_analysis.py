from itertools import permutations

def quick_sort(arr, l, r):
    key = arr[(l+r)//2]
    i = l
    j = r
    cnt = 0

    while (i == l and j == r) or i <= j:
        while arr[i] < key:
            i += 1
            cnt += 1
        cnt += 1
        while key < arr[j]:
            j -= 1
            cnt += 1
        cnt += 1
        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    if l < j:
        cnt += quick_sort(arr, l, j)
    if i < r:
        cnt += quick_sort(arr, i, r)

    return cnt


for n in range(1,10):
    t = (0, [])
    for perm in permutations(list(range(1,n+1))):
        cur = quick_sort(list(perm), 0, len(perm)-1)
        if cur > t[0]:
            t = (cur, perm)
    print(t)

'''
N: 1 Best: (2, (1,))
N: 2 Best: (3, (1, 2))
N: 3 Best: (6, (1, 3, 2))
N: 4 Best: (12, (1, 4, 2, 3))
N: 5 Best: (19, (1, 4, 5, 3, 2))
N: 6 Best: (27, (1, 4, 6, 3, 2, 5))
N: 7 Best: (36, (1, 4, 6, 7, 2, 5, 3))
N: 8 Best: (46, (1, 4, 6, 8, 2, 5, 3, 7))
N: 9 Best: (57, (1, 4, 6, 8, 9, 5, 3, 7, 2))
N: 10 Best: (69, (1, 4, 6, 8, 10, 5, 3, 7, 2, 9))
'''