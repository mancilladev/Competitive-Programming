def solve(arr, last = 0):
    if not arr:
        return 0
    return max(1 + solve(arr[1:],arr[0]), solve(arr[1:], last))

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split(' ')))
    print(solve(A))
