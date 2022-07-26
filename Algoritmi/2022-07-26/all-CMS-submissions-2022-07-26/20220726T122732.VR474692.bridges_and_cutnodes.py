"""
* user:  VR474692
* fname: MASSIMO
* lname: MARTINI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 12:27:32.859199
"""
import sys


t,n,m=map(int,open("input1.txt").readlines()[0].split())

grafo = [ [] for v in range(n) ]
bridges = [1]*(m)
l=0

for i in range(m):
    a,b=map(int,open("input1.txt").readlines()[i+1].split())
    grafo[a].append(b)
    grafo[b].append(a)


def bridge(a,b,l):

    for u in grafo[b]:
     if (u!=a):
        for t in grafo[u]:
                if (t==a):
                    bridges[l]=0


def scrivi():
    with open("output1.txt", "a") as f:
        for element in bridges:
            f.write("%s" % element + "\n")

def scrivi1():
    with open("output1.txt", "a") as f:
        f.write("1"+"\n")

for i in range(m):
    a,b=map(int,open("input1.txt").readlines()[i+1].split())                    
    bridge(a,b,l)
    l=l+1


scrivi()
