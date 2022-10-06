"""
* user:  VR474692
* fname: MASSIMO
* lname: MARTINI
* task:  esamebridges_and_cutnodes
* score: 15.0
* date:  2022-07-26 12:48:49.280889
"""
#!/usr/bin/env python3

import sys


t,n,m=map(int,input().split())

grafo = [ [] for v in range(n) ]
bridges = [1]*(m)
A = []
B = []

for i in range(m):
    a,b=map(int,input().split())
    grafo[a].append(b)
    grafo[b].append(a)
    A.append(a)
    B.append(b)

def bridge(a,b,i):

    for u in grafo[b]:
     if (u!=a):
        for t in grafo[u]:
                if (t==a):
                    bridges[i]=0


def scrivi():
    #with open("output1.txt", "a") as f:
        for element in bridges:
            print(element)


for i,a,b in zip(range(m),A,B):
    bridge(a,b,i)


scrivi()
