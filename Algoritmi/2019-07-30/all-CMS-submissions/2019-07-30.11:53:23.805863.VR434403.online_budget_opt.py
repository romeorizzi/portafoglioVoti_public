"""
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 11:53:23.805863
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Template per soluzione in python per il problema online_budget_opt
Romeo Rizzi, 2019-07-28
"""

MAX_N = 1000000
MAX_VAL = 10

n, B0, t = map(int,input().split())
assert 1 <= n <= MAX_N
assert 0 <= B0

x = list(map(int,input().split()))
q = list(map(int,input().split()))
assert len(x) == n
assert len(q) == n
#print(x)
#print(q)

y = [B0] + [x[i] for i in range(n-1) ]

maxel = -1
maxs_i = set()

i = n-2
while(i>= 0):
    if(q[i] > maxel):
        maxel = q[i]
        maxs_i.add(i + 1)
        print(i)
    i-=1

#for el in maxs_i:
#   print(el)

#cooooode

if t == 1:
    val = 0

    i = 0
    acc = 0
    while(i < n):
        acc += x[i]
        if(i in maxs_i):
            val += (acc*q[i])
            acc = 0
        i+=1

    print(val)
else:
    print(" ".join(map(str, y)))


