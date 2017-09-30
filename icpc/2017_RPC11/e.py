def solve(hand):
    return 'S' if len(set(hand) & set([1,2,3])) >= 2 else 'N'

hand = list(map(int, input().split()))
print(solve(hand))
