import sys


def main():
    alphabet = set('ABCDEFGHIJKLMNOPQRZTUVWXYS')
    for line in sys.stdin:
        ans = line.strip()
        if len(ans) < 1:
            continue
        extras = ans.count('?')
        missing = [c for c in alphabet if c not in ans]
        if len(ans) < 26 or len(missing) > extras:
            print(-1)
            continue
        for q in range(extras):
            ans = ans.replace('?', missing[q], 1)
        ans = ans.strip()
        if alphabet == set(ans):
            print(ans)
        else:
            print(-1)


if __name__ == '__main__':
    main()
