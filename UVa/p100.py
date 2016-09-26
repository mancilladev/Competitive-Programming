import sys
import functools


@functools.lru_cache(None)
def cycle_lenght(n):
    if n == 1:
        return 1
    return cycle_lenght(3 * n + 1 if n % 2 else n / 2) + 1


def main():
    for line in sys.stdin:
        i, j = map(int, line.split())
        print(i, j, max(cycle_lenght(x) for x in range(min(i, j), max(i, j)+1)))


if __name__ == '__main__':
    main()
