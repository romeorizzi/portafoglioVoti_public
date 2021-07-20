"""
* user:  VR460384_id602ngu
* fname: NICOLA
* lname: ASSOLINI
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 10:42:34.411076
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Un template per la tua soluzione di hanoi_with_toddler
   Romeo Rizzi, 2021-06-20
"""
sys.setrecursionlimit(1000000)

DEBUG = False
#DEBUG = True

MAXN = 100000
mosse = [None] * (MAXN)

t, N = map(int,input().split()) # probem type and number of disks
assert 0 <= t <= 1
assert 1 <= N <= MAXN
d = [None] + list(input() + "A")  # the final destinations of the disks (disks numbered from 1). In other words, d encodes the final configuration.
curr_peg = [None] + ['A'] * N
#assert len(d) == N+1
assert len(curr_peg) == N+1
pioli = ['A','B','C']
daddy = False
if DEBUG:
    print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}")

def num_mosse(num_dischi):
    if mosse[num_dischi] != None:
        return mosse[num_dischi]
    """ritorna il numero di mosse necessarie per spostare una torre di n dischi"""
    assert num_dischi >= 0
    if num_dischi == 0:
        mosse[num_dischi] = 0
        return 0
    if num_dischi == 1:   # ? devo per forza gestirlo come un caso base?
        mosse[num_dischi] = 1
        return 1
    mosse[num_dischi] = num_mosse(num_dischi-1) + 1 + num_mosse(num_dischi-1)
    return num_mosse(num_dischi-1) + 1 + num_mosse(num_dischi-1)    

def sposta_disco(n_disco, piolo_from, piolo_to):
    global daddy
    daddy = not daddy
    if daddy:
        print(f"daddy muove il disco {n_disco} dal piolo {piolo_from} al piolo {piolo_to}")
    else:
        print(f"toddler muove il disco {n_disco} dal piolo {piolo_from} al piolo {piolo_to}")


def sposta_torre_vero(num_dischi, piolo_from, piolo_to, piolo_support):
    if num_dischi == 0:
        return   # Fatto!
    sposta_torre_vero(num_dischi-1, piolo_from, piolo_support, piolo_to)
    sposta_disco(num_dischi, piolo_from, piolo_to)
    sposta_torre_vero(num_dischi-1, piolo_support, piolo_to, piolo_from)      

def sposta_torre(num_dischi, piolo_from, piolo_to, level):
    assert num_dischi >= 0
    if num_dischi == 0:
        return
    
    
    
    if piolo_from != piolo_to:
        ll = ['A','B','C']
        ll.remove(piolo_from)
        ll.remove(piolo_to)
        piolo_sup = ll[0]
        sposta_torre_vero(num_dischi-1, piolo_from, piolo_sup, piolo_to)
        sposta_disco(num_dischi, piolo_from, piolo_to)
        sposta_torre(num_dischi-1, piolo_sup, d[level+1], level + 1) 
    else:
        sposta_torre(num_dischi-1, piolo_from, d[level+1], level + 1)

if t == 0:
    print(num_mosse(N)) # TO DO: stampa il numero di mosse
else:
    # d[0] = None
    
    sposta_torre(N, 'A', d[1], 1)
    # TO DO: fornisci la lista esplicita di mosse

