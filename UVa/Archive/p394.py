import sys


def main():
    for line in sys.stdin:
        narrays, ncalculations = map(int, line.split())
        inmemory = {}
        for i in range(narrays):
            ic = input().split()
            key = ic[0]
            inmemory[key] = []
            icnums = [int(x) for x in ic[1:]]
            inmemory[key] = icnums[:3]
            for j in range(icnums[2]):
                inmemory[key].append((icnums[j*2+3], icnums[j*2+4]))
        for i in range(ncalculations):
            ic = input().split()
            key = ic[0]
            references = [int(x) for x in ic[1:]]
            B = inmemory[key][0]
            dims = inmemory[key][3:]
            D = len(dims)
            allC = []
            ans_address = 0
            sumCL = 0
            for j in reversed(range(len(references)+1)):
                L, U = dims[j-1]
                if j == 0:
                    ans_address += (B - sumCL)
                    break
                elif j == D:
                    C = inmemory[key][1]
                    prevL, prevU = L, U
                else:
                    C = allC[-1]*(prevU-prevL+1)
                allC.append(C)
                prevL, prevU = L, U
                ans_address += C*references[j-1]
                sumCL += C*L
            print('{0}{1} = {2}'.format(key, references, ans_address))


if __name__ == '__main__':
    main()
