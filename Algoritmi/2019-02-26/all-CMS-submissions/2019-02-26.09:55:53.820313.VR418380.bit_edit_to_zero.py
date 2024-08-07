"""
* user:  VR418380
* fname: CRUCIANI
* lname: FEDERICA
* task:  bit_edit_to_zero
* score: 50.0
* date:  2019-02-26 09:55:53.820313
"""
# -*- coding: utf-8 -*-
# Template di soluzione per bit_edit_to_zero

from __future__ import print_function
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

#################################################
# INIZIO area entro la quale ti richiediamo/consigliamo di operare.
    
def lsp(n):
    return n & (-n)

def num_uni(n):
    if n == 0:
        return 0
    return 1 + num_uni(n-lsp(n))

def pot_2(n):
    return n == lsp(n)

def num_mosse(n):
    if n == 0:
        return 0
    if num_uni(n) % 2 == 1:
        if n%2 == 1:
            return 1 - num_mosse(n-1)
        else:
            return 1+num_mosse(n+1)
    if lsp(n-lsp(n)) == 2*lsp(n):
        return 1- num_mosse(n-2*lsp(n))
    else:
        return 1+num_mosse(n+2*lsp(n))

def mossa(n):
    assert n >0
    if num_uni(n) % 2 == 1:
        return 1
    else:
        return 2

# FINE area entro la quale ti richiediamo/consigliamo di operare.
#################################################
    
    
p, n = map(int, input().strip().split())
assert 1 <= p <= 2
assert n >= 0
if p  == 1:
    print(num_mosse(n))
if p  == 2:
    print(mossa(n))
