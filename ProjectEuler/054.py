from collections import Counter
from enum import IntEnum, unique

@unique
class Quality(IntEnum):
    """Quality of a poker hand. Higher values beat lower values."""
    high_card = 1
    pair = 2
    two_pairs = 3
    tercia = 4
    straight = 5
    flush = 6
    full_house = 7
    four = 8
    straight_flush = 9

def canonical(hand):
    flush = len(set(suit for __, suit in hand)) == 1
    ranks = sorted('--23456789TJQKA'.find(rank) for rank, __ in hand)
    if ranks == [2, 3, 4, 5, 14]:
        ranks = [1, 2, 3, 4 , 5]
    straight = ranks == list(range(ranks[0], ranks[0] + 5))
    count = Counter(ranks)
    counts = sorted(count.values())
    distinct_ranks = sorted(count, reverse=True, key=lambda v:(count[v], v))
    if flush and straight:      q = Quality.straight_flush
    elif counts == [1, 4]:      q = Quality.four
    elif counts == [2, 3]:      q = Quality.full_house
    elif flush:                 q = Quality.flush
    elif straight:              q = Quality.straight
    elif counts == [1, 1, 3]:   q = Quality.tercia
    elif counts == [1, 2, 2]:   q = Quality.two_pairs
    elif counts == [1,1,1,2]:   q = Quality.pair
    else:                       q = Quality.high_card
    return q, distinct_ranks

def main():
    cnt = 0
    with open('file_054.txt', 'r') as fin:
        for i in range(1000):
            line = fin.readline().strip()
            p1 = line[:14]
            p2 = line[15:]
            if canonical(p1.split()) > canonical(p2.split()):
                cnt += 1
    print(cnt)

if __name__ == '__main__':
    main()
