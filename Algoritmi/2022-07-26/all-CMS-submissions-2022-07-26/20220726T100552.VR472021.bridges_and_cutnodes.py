"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 10:05:52.423408
"""
#!/usr/bin/env python3

from functools import lru_cache


t,n,m = tuple(map(int,input().split()))

E = []
V = set()


for i in range(m):
    v1,v2 = tuple(map(int,input().split()))
    E.append((v1,v2))
    V.add(v1)
    V.add(v2)

#assert len(e) == m
#assert len(v) == n

if t == 1:
    out = [0]*m

    a=set()
    for e in range(1,m):
        v1,v2= E[e]
        a.add(v1)
        a.add(v2)

    if E[0][0] not in a or E[0][1] not in a:
        out[0]=1

    for e,i in zip(E,range(m)):
        E1 = E[:]
        E1.remove(e)
        a1 = {E[0][0],E[0][1]}
        a2 = set()
        #print('NUOVO: ', e)

        for e1 in E1:
            if e1[0] in a1 or e1[1] in a1:
                #print('if')
                a1.add(e1[0])
                a1.add(e1[1])
            else: 
                #print('else')
                a2.add(e1[0])
                a2.add(e1[1])

            if a1.intersection(a2) != set():
                a1 = a1 | a2
                a2 = set()

        #print(a1)
        #print(a2)
        
        if len(a2) != 0 or len(a1) != n or a1 & a2 != set():
            out[i] = 1

if t == 2:
    
    out = [0]*n

    for v,i in zip(V,range(n)):
        V1 = V.copy()
        V1.remove(v)
        E1 = []

        for e in E:
            if e[1] != v and e[0] != v:
                E1.append(e)
        if len(E1) == 0:
            out[i] = 1
        else:
            a1 = {E1[0][0],E1[0][1]}
            a2 = set()

            for e1 in E1:
                if e1[0] in a1 or e1[1] in a1:
                    #print('if')
                    a1.add(e1[0])
                    a1.add(e1[1])
                else: 
                    #print('else')
                    a2.add(e1[0])
                    a2.add(e1[1])

                if a1.intersection(a2) != set():
                    a1 = a1 | a2
                    a2 = set()
            
            if len(a2) != 0 or len(a1) != n-1 or a1 & a2 != set():
                out[i] = 1


    

#print(out)

for o in out:
    print(o)

    


