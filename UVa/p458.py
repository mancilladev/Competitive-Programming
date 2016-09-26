import sys


def decrypt(c, step):
    return chr(ord(c) + step)


def main():
    word_list = ['the', 'in', 'for', 'of', 'is', 'so', 'and', '...', 'with', 'to', 'in', 'that', 'it']
    for line in sys.stdin:
        for step in range(-127, 127):
            try:
                decoded = ''.join(decrypt(c, step) for c in line)
            except ValueError:
                continue
            if len(decoded.split())==1 and any(word in decoded.lower().split()[0] for word in word_list):
                print(decoded[:-1])
                break
            if ' ' in decoded and any(word in decoded.lower() for word in word_list):
                print(decoded[:-1])
                break


if __name__ == '__main__':
    main()
