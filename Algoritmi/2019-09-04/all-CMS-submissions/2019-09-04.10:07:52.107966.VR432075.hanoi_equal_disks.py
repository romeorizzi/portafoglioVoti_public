"""
* user:  VR432075
* fname: BUSATTO
* lname: ALESSANDRO
* task:  Prob2_hanoi_equal_disks
* score: 0.0
* date:  2019-09-04 10:07:52.107966
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Un template per la tua soluzione di hanoi_equal_disks
   Romeo Rizzi, 2019-08-28
"""

DEBUG = False
#DEBUG = True

MAXN = 100000

t, N = map(int,input().split()) # probem type and number of disks
assert 0 <= t <= 1
assert 1 <= N <= MAXN
d = [None] + list(map(int,input().split())) # the diameters of the disks numbered form disk 1
assert len(d) == N+1

# print(t)
# print(d)


if DEBUG:
    print("problem type t="+str(t)+", number of disks N="+str(N)+", diameters' list d="+str(d)+"\n")


def sposta_disco(i, piolo_from, piolo_to):
        print("sposta il disco "+str(i)+" dal piolo "+str(piolo_from)+" al piolo "+str(piolo_to)+"\n")

def rec_hanoi(disk,da,a,aux):
    if disk==1:
        sposta_disco(disk,da,a)
        return
    if d[disk]==d[disk-1]:
        rec_hanoi(disk-2,da,aux,a)
        sposta_disco(disk-1,da,a)
        sposta_disco(disk,da,a)
        rec_hanoi(disk-2, aux, a, da)
    else:
        rec_hanoi(disk-1,da,aux,a)
        sposta_disco(disk,da,a)
        rec_hanoi(disk-1, aux, a, da)

# def rec_hanoi(disk,da,a,aux):
#     if disk==1:
#         sposta_disco(disk,da,a)
#         return
#     rec_hanoi(disk-1,da,aux,a)
#     sposta_disco(disk,da,a)
#     rec_hanoi(disk-1, aux, a, da)

if t == 0:
    print(numMosse)
else:
    #sposta_disco(1, 'A', 'B')
    rec_hanoi(N,'A','B','C')

numMosse = 0

def contaMosse(n, da, a):
    global numMosse
    numMosse+=1




    


