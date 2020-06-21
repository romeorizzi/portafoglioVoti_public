"""
* user:  VR425207
* fname: IMOLA
* lname: DAVIDE
* task:  tree_transcode_disc
* score: 10.0
* date:  2019-07-30 10:12:28.128579
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
def translatorDaCodifica1A2(seq, index, total):
    if (seq[index] == 1):
        print(seq[index], end=" ")
        return index + 1
    
    sum = 1
    temp = index
    while sum != total:
        print("Somma {}".format(sum))
        temp = translatorDaCodifica1A2(seq=seq, index=temp+1, total=seq[temp])
        sum = sum + seq[index]
    
    print(seq[index], end=" ")
    return index + 1

MAX_N = 1000000

seq = list(map(int,input().split()))
codifica = seq[0]

nuovaCodifica = 3 - codifica
print(nuovaCodifica, end=" ")

if nuovaCodifica == 1:
    i = len(seq) - 1
    while i>0:
        print(seq[i], end=" ")
        i = i - 1
else:
    translatorDaCodifica1A2(seq=seq, index=2, total=seq[1])
    print(seq[1], end=" ")
    
print()
