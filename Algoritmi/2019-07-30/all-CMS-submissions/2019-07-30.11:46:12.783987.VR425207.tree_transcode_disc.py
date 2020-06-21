"""
* user:  VR425207
* fname: IMOLA
* lname: DAVIDE
* task:  tree_transcode_disc
* score: 40.0
* date:  2019-07-30 11:46:12.783987
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
    sum = 1
    while sum != total:
        if index > len(seq) - 1:
            return
        sum = sum + seq[index]
        temp = index + 1
        if seq[index] > 1:
            temp = translatorDaCodifica1A2(seq=seq, index=index+1, total=seq[index])
        print(seq[index], end=" ")
        index = temp
    return index
        

MAX_N = 1000000

seq = list(map(int,input().split()))
codifica = seq.pop(0)

nuovaCodifica = 3 - codifica
print(nuovaCodifica, end=" ")

if nuovaCodifica == 1:
    i = len(seq) - 1
    while i>=0:
        print(seq[i], end=" ")
        i = i - 1
else:
    translatorDaCodifica1A2(seq=seq, index=0, total=seq[0])
    
print()
