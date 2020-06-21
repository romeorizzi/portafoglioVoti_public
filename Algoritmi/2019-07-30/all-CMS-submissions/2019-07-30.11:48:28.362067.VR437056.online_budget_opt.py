"""
* user:  VR437056
* fname: MARTINI
* lname: MICHELE
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 11:48:28.362067
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

MAX_N = 15 # 500
MAX_VAL = 10

n, B0, t = map(int,input().split())
assert 1 <= n <= MAX_N
assert 0 <= B0

x = list(map(int,input().split()))
q = list(map(int,input().split()))
assert len(x) == n
assert len(q) == n

y = [B0] + [x[i] for i in range(n-1) ]

prev = [0] * MAX_N
actual = [0] * MAX_N
maximum = B0

for step in range(n):
    for j in range(maximum + 1):
        actual[maximum - j] = max(prev[maximum - j], actual[maximum - j + 1] + q[step] * (j-1))
    if step != (n-1):
        for i in range(maximum, -1, -1):
            temp = actual[i]
            actual[i] = 0
            actual[i+x[step]] = temp
    maximum += x[step]
    prev = actual

print(prev[0])

#if t == 1:
#    print( 42 )
#else:
#    print(" ".join(map(str, y)))


