filename = 'C'
fin = open(f'{filename}.in', 'r')
fout = open(f'{filename}.out', 'w')

def getDivisor(n):
    top = int(n**0.5)+2
    if not (n&1):
        return 2
    for i in range(3, top, 2):
        if n%i == 0:
            return i
    return None

def getBaseValues(s):
    return [int(s, b) for b in range(2, 11)]

def isJamCoin(s):
    divisors = []
    base_values = getBaseValues(s)
    for n in base_values:
        d = getDivisor(n)
        if not d:
            return None
        else:
            divisors.append(d)
    return divisors

def sumBit(s):
    n = int(s, 2)
    n += 2
    while not (n & 1):
        n += 1
    return bin(n)[2:]

def solve(N, J):
    ans = []
    coin = '1' + ('0' * (N - 2)) + '1'
    while len(ans) < J:
        intento = isJamCoin(coin)
        if intento:
            print(len(ans))
            ans.append([coin + coin, *isJamCoin(coin+coin)])
        coin = sumBit(coin)
        if len(coin) > N:
            assert False
    return ans

T = int(fin.readline())
for tt in range(T):
    fout.write(f'Case #{tt+1}:\n')
    N, J = map(int, fin.readline().split(' '))
    for line in solve(N, J):
        fout.write(' '.join(map(str, line)))
        fout.write('\n')
