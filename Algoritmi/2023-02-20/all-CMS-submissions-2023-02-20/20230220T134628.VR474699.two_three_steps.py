"""
* user:  VR474699
* fname: ALESSANDRO
* lname: RODEGHERO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:46:28.832424
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

#import sys
#sys.setrecursionlimit(10**9)

fin = open('input.txt','r')

n = int(fin.readline())
val = map(int,fin.readline().strip().split())

#print(val)

def dls(lista, somma, step):

    if len(lista) <= 2:
        #print('goal',somma)
        return somma
    part = 0
    for s in [2,3]:
        if len(lista) > s:
            tmp = lista[s:]
            #print(s, tmp)
            qua = dls(tmp, somma+tmp[0], s)
            if qua > part: part = qua
    
    return part

if n != 0: RES = dls(val, val[0], 0)
else: RES = 0

#print(str(RES)+'\n'+' aaaaaaa')
fout = open('output.txt','w')
fout.write(str(RES)+'\n')

fin.close()
fout.close()