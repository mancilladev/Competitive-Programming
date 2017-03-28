#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p1.out", "w")

T = int(fin.readline())
for tt in xrange(T):
    S = fin.readline().strip()
    ans = ''
    fout.write("Case #" + str(tt+1) + ": " + ans + "\n")
