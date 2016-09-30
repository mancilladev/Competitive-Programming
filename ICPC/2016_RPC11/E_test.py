import sys
from itertools import permutations


def sum(l, base):
    suma = int('0',base)
    for e in l:
        suma += int(e,base)
    return suma


def remove(s, l):
    for c in l:
        s.replace(str(c),'')
    print(s, l)
    return s


def main():
    base_elems = [0,1,2,3]
    base = len(base_elems)
    for line in sys.stdin:
        N = int(line, 16)

        S = []
        for i in range(N):
            S.append(input())

        suma = int('0',4)
        s = S
        p = base_elems

        print('S =', S)
        print('p =', p)
        print()
        for i in range(1, base):
            print('remover = ', p[:i])
            s = [ remove(e,p[:i]) for e in s ]
            suma += sum([str(int(e,4)) for e in s], 4)
            print('s = ', s)
            print('pasos suma =', [int(e,4) for e in s])
        print('suma =', suma)
        print()


if __name__ == '__main__':
    main()
