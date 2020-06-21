"""
* user:  VR425207
* fname: IMOLA
* lname: DAVIDE
* task:  tree_transcode_disc
* score: 20.0
* date:  2019-07-30 09:26:40.222332
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Template per soluzione in python per il problema tree_transcode_disc
Romeo Rizzi, 2019-07-28
"""

MAX_N = 1000000

seq = list(map(int,input().split()))
codifica = seq[0]

nuovaCodifica = 3 - codifica
print(nuovaCodifica, end=" ")

i = len(seq) - 1
while i>0:
    print(seq[i], end=" ")
    i = i - 1
    
print()
