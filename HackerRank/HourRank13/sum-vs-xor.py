#!/bin/python3

import sys


n = int(input().strip())
if n == 0:
    print(1)
else:
    b = str(bin(n))[2:]
    print(2 ** list(b).count('0'))
