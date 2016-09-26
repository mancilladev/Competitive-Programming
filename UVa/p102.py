import sys
import itertools


def main():
    colors = {'B': 0, 'G': 1, 'C': 2}
    for line in sys.stdin:
        int_list = [int(x) for x in line.split()]
        bin1, bin2, bin3 = int_list[:3], int_list[3:6], int_list[6:]
        total_sum = sum(int_list)
        ans = [('B', 'C', 'G'), total_sum]
        for order in sorted(itertools.permutations('BGC')):
            val = total_sum - sum([bin1[colors[order[0]]], bin2[colors[order[1]]], bin3[colors[order[2]]]])
            if val < ans[1]:
                ans = [order, val]
        print('{0} {1}'.format(''.join(ans[0]), ans[1]))


if __name__ == '__main__':
    main()
