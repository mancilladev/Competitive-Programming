import sys

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line)

    cases = []

    for i, line in enumerate(lines):
        if i % 2 == 0:
            continue
        cases.append([
            lines[i-1],
            lines[i]
        ])


    solutions = []
    for case in cases:
        solutions.append(solveCase(case))
    
    for sol in solutions:
        print(sol)


def solveCase(case):
    colsLen = int(case[0].strip())
    cols = case[1].strip().split(' ')
    cols = [int(c) for c in cols if not c == '']
    cols = cols[:colsLen]

    Max = max(cols)
    C = Max

    for h in range(1, Max+1):
        if (C*2)+1 > len(cols):
            pir = genPiramidCols(len(cols))
            C = max(pir)
        else:
            pir = genPiramid(C)

        if sum(pir) > sum(cols):
            C -= 1
            continue


        if testPiramidColums(pir, cols):
            return C
        C -= 1

    return 0


def testPiramidColums(pir, cols):
    mvs = len(cols) - len(pir) + 1

    for m in range(0, mvs):
        passt = True
        for j, p in enumerate(pir):
            if pir[j] > cols[j+m]:
                passt = False
                break
        if passt:
            return True

    return False



def genPiramid(heigth):
    pir = []
    pir += list(range(1,heigth))
    pir += list(range(heigth,0,-1))
    return pir


def genPiramidCols(cols):
    pir = []
    if cols % 2 == 0:
        cols -= 1
    mitad = cols//2
    pir += list(range(1,mitad+1))
    pir += list(range(mitad+1, 0, -1))
    return pir


if __name__ == '__main__':
    main()
