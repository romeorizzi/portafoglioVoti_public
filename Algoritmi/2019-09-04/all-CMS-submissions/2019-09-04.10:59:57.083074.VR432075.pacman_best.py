"""
* user:  VR432075
* fname: BUSATTO
* lname: ALESSANDRO
* task:  Prob3_pacman_best
* score: 0.0
* date:  2019-09-04 10:59:57.083074
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

from __future__ import print_function
import sys
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

"""Soluzione di pacman_best (ricorsione senza memoizzazione) 
   Autore: Romeo Rizzi, 2019-08-26
   Descrizione: ricorsione semplice. Algoritmo esponenziale.
"""

def print_matrix(matrice):
    for row in matrice:
        print(row)


DEBUG1 = True
DEBUG2 = False
DEBUG3 = False

MAXBLUE = 9
MAXM = 1000
MAXN = 1000

M, N = map(int,input().split())
assert 1 <= M <= MAXM
assert 1 <= N <= MAXN

mappa = ['#' * (N+1)]
for line in sys.stdin:
    mappa.append('#' + line.rstrip('\n\r'))

assert len(mappa) == M+1
if DEBUG1:
    #print(mappa, file=sys.stderr)
    print_matrix(mappa)


def check(mappa,r,c,power,np,nf):
   # print(r, c, mappa[r][c])
    if r == M and c==N:
        return True, np, nf
    if mappa[r][c]=="#":
        return False, np, nf
    if mappa[r][c]=="*" and power<=0:
        nf+=1
        return False, np, nf
    if mappa[r][c]>="0" and mappa[r][c]<="6" and int(mappa[r][c])>power:
        np+=1
        power=int(mappa[r][c])
    if(c<N):
        return check(mappa,r,c+1,power-1,np,nf)
    if(r<M):
        return check(mappa,r+1,c,power-1,np,nf)
    
    


exists_complete, best_complete_pills,best_complete_ghosts = check(mappa,1,1,0,0,0)





# exists_complete=0
# best_complete_pills=0
# best_complete_ghosts =0

if exists_complete:
    print("1 "+str(best_complete_ghosts)+" "+str(best_complete_pills))
else:
    print("0 "+str(best_complete_ghosts)+" "+str(best_complete_pills))

