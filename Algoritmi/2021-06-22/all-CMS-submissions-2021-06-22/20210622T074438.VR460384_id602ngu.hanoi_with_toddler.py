"""
* user:  VR460384_id602ngu
* fname: NICOLA
* lname: ASSOLINI
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 07:44:38.643434
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

t, N = map(int,input().split()) # probem type and number of disks
assert 0 <= t <= 1
assert 1 <= N <= MAXN
d = [None] + list(input()) # the final destinations of the disks (disks numbered from 1). In other words, d encodes the final configuration.
curr_peg = [None] + ['A'] * N
assert len(d) == N+1
assert len(curr_peg) == N+1
pioli = ['A','B','C']
daddy = False
if DEBUG:
    print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}")

def num_mosse(num_dischi):
    """ritorna il numero di mosse necessarie per spostare una torre di n dischi"""
    assert num_dischi >= 0
    if num_dischi == 0:
        return 0
    if num_dischi == 1:   # ? devo per forza gestirlo come un caso base?
        return 1
    return num_mosse(num_dischi-1) + 1 + num_mosse(num_dischi-1)    

def sposta_disco(n_disco, piolo_from, piolo_to):
    global daddy
    daddy = not daddy
    if daddy:
        print(f"daddy muove il disco {n_disco} dal piolo {pioli[piolo_from-1]} al piolo {pioli[piolo_to-1]}")
    else:
        print(f"toddler muove il disco {n_disco} dal piolo {pioli[piolo_from-1]} al piolo {pioli[piolo_to-1]}")

def sposta_torre(num_dischi, piolo_from, piolo_to, piolo_support):
    """stampa su stdout le mosse una ad una. Secondo il formato così esemplificato (per num_dischi = 2):
        sposta il disco 1 dal piolo 1 al piolo 2
        sposta il disco 2 dal piolo 1 al piolo 3
        sposta il disco 1 dal piolo 2 al piolo 3  
    """
    assert num_dischi >= 0
    if num_dischi == 0:
        return   # Fatto!
    sposta_torre(num_dischi-1, piolo_from, piolo_support, piolo_to)
    sposta_disco(num_dischi, piolo_from, piolo_to)
    sposta_torre(num_dischi-1, piolo_support, piolo_to, piolo_from) 


# def sposta_disco(i, peg_from, peg_to):
#     assert curr_peg[i] == peg_from
#     print(f"sposta il disco {i} dal peg {peg_from} al peg {peg_to}")
#     curr_peg[i] = peg_to

# def sposta_intera_torre(n, peg_from, peg_to, peg_aux):
#     """assume che tutti i dischi i <= n siano uno sopra l'altro in torre sul peg <peg_from>.
#        Sposta questa intera torre sul peg <peg_to>, impiegano il minor numero di mosse possibile.
#        Si assume che <peg_aux> indichi il terzo peg."""
#     pass    

    
if t == 0:
    print(num_mosse(N)) # TO DO: stampa il numero di mosse
else:
    sposta_torre(N,1,2,3)
    # TO DO: fornisci la lista esplicita di mosse

