import sys

def main():
    for line in sys.stdin:
        numbs = line.strip().split(' ')
        numbs = [n for n in numbs if not n == '']

        a = int(numbs[0])
        b = int(numbs[1])
        c = int(numbs[2])
        if (a == b) or (a == c) or (b == c) or (c == b):
            print ('S')
        elif (a + b == c) or (a + c == b) or (b + c == a): 
            print('S')
        else:
            print('N')


if __name__ == '__main__':
    main()

