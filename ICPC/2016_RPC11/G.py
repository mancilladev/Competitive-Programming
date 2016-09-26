import sys
from pprint import pprint
from bisect import bisect_left, insort_left


def binary_search(a,x):
    pos = bisect_left(a,x)
    return (pos if pos != None and a[pos] == x else -1)


def main():
    for line in sys.stdin:
        N, P = map(int, line.split())
        black = [[1 for j in range(N)] for i in range(N)]
        white = [[1 for j in range(N)] for i in range(N)]
        bcount = P
        wcount = P
        bhas = []
        whas = []
        for i in range(P):
            a, b = map(int, input().split())
            white[a-1][b-1] = 0;
        for i in range(P):
            a, b = map(int, input().split())
            black[a-1][b-1] = 0;
        # pprint(black)
        # print()
        # pprint(white)
        # print()

        for i in range(N-2,-1,-1):
            for j in range(N-2,-1,-1):
                minb = min(black[i+1][j], black[i+1][j+1], black[i][j+1])
                minw = min(white[i+1][j], white[i+1][j+1], white[i][j+1])
                p = (i+1,j+1)
                if black[i][j]:
                    black[i][j] = minb+1
                if white[i][j]:
                    white[i][j] = minw+1
                if (black[i][j]==2 and min(minw,white[i][j])==0) or (black[i][j]>2 and binary_search(bhas,p)!=-1):
                    insort_left(bhas, (i,j))
                    bcount+=minb
                if (white[i][j]==2 and min(minb,black[i][j])==0) or (white[i][j]>2 and binary_search(whas,p)!=-1):
                    insort_left(whas, (i,j))
                    wcount+=minw
        # pprint(black)
        # print()
        # pprint(white)
        # print()
        # print('black:',bcount)
        # print('white:',wcount)
        print(bcount, wcount)


if __name__ == '__main__':
    main()
