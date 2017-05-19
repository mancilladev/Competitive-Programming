from fractions import Fraction

n = -1
f = Fraction(3/7 - 10**n).limit_denominator()
while f.denominator != 7 and f.denominator <= 1000000:
    n -= 1
    f = Fraction(3/7 - 10**n).limit_denominator()

print( Fraction(3/7 - 10**(n+1)).limit_denominator() )
