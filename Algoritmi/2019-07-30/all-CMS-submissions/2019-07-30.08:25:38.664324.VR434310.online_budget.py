"""
* user:  VR434310
* fname: DI MATTEO
* lname: ROSARIO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 08:25:38.664324
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Template per soluzione in python per il problema online_budget
Romeo Rizzi, 2019-07-28   
"""

MAX_N = 500
MAX_VAL = 10

n, B0 = map(int,input().split())
assert 1 <= n <= MAX_N
assert 0 <= B0

x = list(map(int,input().split()))
assert len(x) == n
#print(x)

sum=0
for h in range(x):
    sum=sum+x(h)
    
totale=0

for j in range(n)
    totale=x(1)+1


print(totale)
