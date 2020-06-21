"""
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  bit_edit_to_zero
* score: 0.0
* date:  2019-02-26 12:18:06.574195
"""
from __future__ import print_function
import sys

if sys.version_info <(3,0):
    input= raw_input

def lsp(n):
    return n & (-n)

def pot_2(n):
    return n == lsp(n)

def n_uni(n):
    if n == 0:
        return 0
    return 1 + numero_uni(n - lsp(n))

def mosse(n):
    r=0
    while n!=0:
        r += 1
        if n_uni(n)%2 ==1:
            if n%2 ==1:
                n=n-1
            else:
                n=n+1
        else:
            if lsp(n-lsp(n))==2*lsp(n):
                n=n-2*lsp(n)
            else:
                n=n+2*lsp(n)
    return risp

    
def mossa(n):
    assert n > 0
    if n_uni(n) %2 == 1:
        return 1
    else:
        return 2


p,n= map(int,input().strip().split())
assert 1<=p <=2
assert n>=0
if p==1:
    print(mosse(n))
if p==2:
    print(mossa(n))    