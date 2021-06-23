"""
* user:  VR463652_id646onp
* fname: ALEARDO
* lname: LODI
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 12:14:04.616127
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
import os

# if sys.version_info < (3, 0):
#     input = raw_input  # in python2, raw_input svolge la funzione della primitiva input in python3

"""Un template per la tua soluzione di hanoi_with_toddler
   Romeo Rizzi, 2021-06-20
"""
sys.setrecursionlimit(1000000)

DEBUG = True
DEBUG = False

MAXN = 100000
DEPTH = 0
t, N = map(int, input().split())  # probem type and number of disks
# t = 1
# N = 3
assert 0 <= t <= 1
assert 1 <= N <= MAXN
# d = [None, 'B', 'B', 'B']
d = [None] + list(
    input())  # the final destinations of the disks (disks numbered from 1). In other words, d encodes the final configuration.
curr_peg = [None] + ['O'] * N
assert len(d) == N + 1
assert len(curr_peg) == N + 1
if DEBUG:
    print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}")


def sposta_disco(i, peg_from, peg_to):
    global DEBUG
    if DEBUG:
        print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}, val i = {i}")

    # assert curr_peg[i] == peg_from
    global DEPTH
    DEPTH = DEPTH + 1
    if DEPTH % 2 != 0:
        print(f"daddy muove il disco {i} dal piolo {peg_from} al piolo {peg_to}")
    else:
        print(f"toddler muove il disco {i} dal piolo {peg_from} al piolo {peg_to}")


    curr_peg[i] = peg_to


def sposta_intera_torre(n, peg_from, peg_to, peg_aux):
    """assume che tutti i dischi i <= n siano uno sopra l'altro in torre sul peg <peg_from>.
       Sposta questa intera torre sul peg <peg_to>, impiegano il minor numero di mosse possibile.
       Si assume che <peg_aux> indichi il terzo peg."""
    if n == 1:
        sposta_disco(1, peg_from, peg_to)
        return;

    sposta_intera_torre(n-1, peg_from, peg_aux, peg_to)
    sposta_disco(n, peg_from, peg_to)
    sposta_intera_torre(n-1, peg_aux, peg_to, peg_from)

    pass


if t == 0:
    sys.stdout = open(os.devnull, 'w')

for i in reversed(range(1, N+1)):
    list_valori = ['A', 'B', 'C']
    prevedente_valore = "A" if i != N+1 else d[i+1]
    if i != 1:
        list_valori.remove(d[i])
        list_valori.remove(prevedente_valore)

    if i == 1:
        prevedente_valore = d[i]
        list_valori = d[0]
        i = 2

    if curr_peg[i] == d[i]:
        continue
    sposta_intera_torre(i-1, prevedente_valore, list_valori[0], d[i])
    sposta_disco(i, prevedente_valore, d[i])
    if DEBUG:
        print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}, val i = {i}")

    if curr_peg == d:
        break

if t == 0:
    sys.stdout = sys.__stdout__
    print(DEPTH)
