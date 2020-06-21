"""
* user:  VR437056
* fname: MARTINI
* lname: MICHELE
* task:  online_budget
* score: 100.0
* date:  2019-07-30 10:59:08.094044
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
from itertools import permutations
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

MAX_N = 500
MAX_VAL = 10


n, B0 = map(int,input().split())
assert 1 <= n <= MAX_N
assert 0 <= B0

x = list(map(int,input().split()))
assert len(x) == n

prev = [0] * MAX_N
actual = [0] * MAX_N
prev[B0] = 1
maximum = B0

for step in range(n):
    for i in range(maximum, -1, -1):
        actual[i] = prev[i] + actual[i+1]
    for i in range(maximum, -1, -1):
        temp = actual[i]
        actual[i] = 0
        actual[i+x[step]] = temp
    maximum += x[step]
    prev = actual

sum = 0
for i in range(maximum + 1):
    sum = (sum + prev[i]) % 1000000007
print(sum)

