"""
* user:  VR474699
* fname: ALESSANDRO
* lname: RODEGHERO
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:12:56.250054
"""
import sys
sys.setrecursionlimit(10**9)

with open('input.txt','r') as f:
    lines = f.readlines()


n = int(input())
val = map(int,input().split())

#n = int(lines[0][0])
#val = map(int,lines[1].strip().split())

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

RES = dls(val, 0, 0)
#print(RES)
with open('output.txt','w') as f:
    f.write(str(RES))

exit(0)

