from functools import reduce
def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)
print('\n'.join(str(reduce(lambda a,b: int(a*b/gcd(a,b)), [x for x in range(1,int(input())+1)])) for i in range(int(input()))))
