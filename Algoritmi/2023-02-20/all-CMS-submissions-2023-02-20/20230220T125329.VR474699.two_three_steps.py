"""
* user:  VR474699
* fname: ALESSANDRO
* lname: RODEGHERO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:53:29.161780
"""
import sys
sys.setrecursionlimit(10**9)

with open('input.txt','r') as f:
    lines = f.readlines()

N = int(lines[0][0])
val = map(int,lines[1].strip().split())

print(val)

sums = set()
def dls(lista, somma, step):
    if len(lista) < step+1:
        #print('goal',somma)
        sums.add(somma)
        return somma
    part = 0
    for s in [2,3]:
        if len(lista) >= s+1:
            tmp = lista[s:]
            dls(tmp, somma+tmp[0], s)
        else: sums.add(somma)
    
    return None

RES = dls(val, 0, 0)


RES = max(sums)
#print(RES)
with open('output.txt','w') as f:
    f.write(str(RES))

