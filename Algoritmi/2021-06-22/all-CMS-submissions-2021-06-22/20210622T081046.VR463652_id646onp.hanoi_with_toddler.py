"""
* user:  VR463652_id646onp
* fname: ALEARDO
* lname: LODI
* task:  hanoi_with_toddler
* score: 10.0
* date:  2021-06-22 08:10:46.176093
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys

# if sys.version_info < (3, 0):
#     input = raw_input  # in python2, raw_input svolge la funzione della primitiva input in python3

"""Un template per la tua soluzione di hanoi_with_toddler
   Romeo Rizzi, 2021-06-20
"""
sys.setrecursionlimit(1000000)

DEBUG = False
# DEBUG = True

MAXN = 100000

t, N = map(int, input().split())  # probem type and number of disks
# t = 1
# N = 3
assert 0 <= t <= 1
assert 1 <= N <= MAXN
# d = [None, 'B', 'B', 'B']
d = [None] + list(
    input())  # the final destinations of the disks (disks numbered from 1). In other words, d encodes the final configuration.
curr_peg = [None] + ['A'] * N
assert len(d) == N + 1
assert len(curr_peg) == N + 1
if DEBUG:
    print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}")


def sposta_disco(i, peg_from, peg_to):
    assert curr_peg[i] == peg_from
    print(f"sposta il disco {i} dal peg {peg_from} al peg {peg_to}")
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

    # peg_buffer = None
    # for i in range(1, n):
    #     print(i)
    #     sposta_disco(i, peg_from, peg_to)
    #     peg_buffer = peg_aux
    #     peg_aux = peg_to
    #     peg_to = peg_buffer
    #
    # sposta_disco(1, peg_to, peg_aux)
    # print(peg_from)
    # print(peg_to)
    # print(f"problem type t={t}, number of disks N={N}, destinations' list d={d}, curr_peg = {curr_peg}")
    # sposta_intera_torre(n-1, peg_from, peg_to, peg_aux)
    # for i in range(1, n-1):
    #     sposta_disco(i, peg_aux, peg_to)
    #     peg_buffer = peg_aux
    #     peg_aux = peg_to
    #     peg_to = peg_buffer
    #
    # sposta_intera_torre(n-1, peg_from, peg_aux, peg_to)

    pass


if t == 0:
    mosse = pow(2, N) - 1  # TO DO: stampa il numero di mosse
    print(mosse)
else:
# TO DO: fornisci la lista esplicita di mosse
    sposta_intera_torre(N, "A", "B", "C")
    i = 0