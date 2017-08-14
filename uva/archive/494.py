import sys
import re


def main():
    for line in sys.stdin:
        words = re.findall(r"[\w']+", line)
        print(len(words))


if __name__ == '__main__':
    main()
