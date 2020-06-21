"""
* user:  VR432075
* fname: BUSATTO
* lname: ALESSANDRO
* task:  Prob3_pacman_best
* score: 10.0
* date:  2019-09-04 11:41:14.268055
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
#if DEBUG1:
    #print(mappa, file=sys.stderr)
    #print_matrix(mappa)


def check(mappa,r,c,power,np,nf):
    exists_complete_d=0
    best_complete_pills_d=0
    best_complete_ghosts_d=0
    exists_complete_r=0
    best_complete_pills_r=0
    best_complete_ghosts_r=0
   # print(r, c, mappa[r][c])
    if r == M and c==N: 
        return True, np, nf
    if mappa[r][c]=="#":
        return False, np, nf
    if mappa[r][c]=="*" and power<=0:
        nf+=1
        return False, np, nf
    if mappa[r][c]>="0" and mappa[r][c]<="6": 
        np+=1
        if int(mappa[r][c])>power:
            power=int(mappa[r][c])
    if(c<N):
        exists_complete_r, best_complete_pills_r,best_complete_ghosts_r=check(mappa,r,c+1,power-1,np,nf)
    if(r<M):
        exists_complete_d, best_complete_pills_d,best_complete_ghosts_d=check(mappa,r+1,c,power-1,np,nf)
    if exists_complete_r and exists_complete_d:
        if best_complete_ghosts_r==best_complete_ghosts_d:
            return exists_complete_r, max(best_complete_pills_r,best_complete_pills_d),best_complete_ghosts_r
        if best_complete_ghosts_r>best_complete_ghosts_d:
            return exists_complete_r, best_complete_pills_r,best_complete_ghosts_r
        else:
             return exists_complete_d, best_complete_pills_d,best_complete_ghosts_d
    if exists_complete_r == False and exists_complete_d == False:
        if best_complete_ghosts_r==best_complete_ghosts_d:
            return exists_complete_r, max(best_complete_pills_r,best_complete_pills_d),best_complete_ghosts_r
        if best_complete_ghosts_r>best_complete_ghosts_d:
            return exists_complete_r, best_complete_pills_r,best_complete_ghosts_r
        else:
            return exists_complete_d, best_complete_pills_d,best_complete_ghosts_d
    if exists_complete_d:
        return exists_complete_d, best_complete_pills_d,best_complete_ghosts_d
    else:
        return exists_complete_r, best_complete_pills_r,best_complete_ghosts_r

    


exists_complete, best_complete_pills,best_complete_ghosts = check(mappa,1,1,0,0,0)





# exists_complete=0
# best_complete_pills=0
# best_complete_ghosts =0

if exists_complete:
    print("1 "+str(best_complete_ghosts)+" "+str(best_complete_pills))
else:
    print("0 "+str(best_complete_ghosts)+" "+str(best_complete_pills))

