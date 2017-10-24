from datetime import datetime, timedelta

def main():
    while True:
        try:
            n, d, m, y = map(int, input().split(' '))
        except:
            break
        if all(x == 0 for x in [n,d,m,y]):
            break
        date = datetime.strptime('{}/{}/{}'.format(d,m,y), '%d/%m/%Y')
        date += timedelta(days=n)
        print('{:%-d %-m %Y}'.format(date))

if __name__ == '__main__':
    main()
