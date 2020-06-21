"""
* user:  VR434310
* fname: DI MATTEO
* lname: ROSARIO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:27:53.208658
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

totale=1

if n=1 :
    print(totale+B0)

else:
    for i in range(B0+1) :
        totale=totale+i
    print(totale)
