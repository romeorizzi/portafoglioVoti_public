"""
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  bit_edit_to_zero
* score: 80.0
* date:  2019-02-26 10:30:24.075332
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
    if n==0:
        return 0
    return 1+ num_uni(n-lsp(n))

def pot_2(n):
    return n==lsp(n)

def num_mosse(n):
    m=0
    while n!=0:
        if num_uni(n)%2 ==1:
            if n%2 ==1:
                n=n-1
            else:
                n=n+1
        else:
            if lsp(n-lsp(n))==2*lsp(n):
                n=n-2*lsp(n)
            else:
                n=n+2*lsp(n)
        m+=1
    return m

def mossa(n):
    assert n>0
    if num_uni(n)%2 ==1:
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
    
