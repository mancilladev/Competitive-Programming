import sys

def main():
    vocals = set('aeiou')
    for line in sys.stdin:
        laugh = [x for x in line if x in vocals]
        if laugh and laugh == laugh[::-1]:
            print('S')
        else:
            print('N')

if __name__ == '__main__':
    main()
