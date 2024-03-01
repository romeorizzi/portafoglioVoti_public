#!/usr/bin/env python3
import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

ONE = "[]"
TWO = "[--]"

COSTANTE = 1000000007

def saveSol(pos_write, prefix):
    result = ""
    for i in range(pos_write):
        if(prefix[i] == '1'):
            result += ONE
        elif prefix[i] == '2':
            result += TWO
    L.append(result)
    



def listaPiastrelle(n, pos_write, prefix):
    if(n == 0):
        saveSol(pos_write, prefix)
        return
    
    prefix[pos_write] = '1'
    listaPiastrelle(n-1, pos_write+1, prefix)

    if(n>=2):
        prefix[pos_write] = '2'
        listaPiastrelle(n-2, pos_write+1, prefix)



T = int(input())

for _ in range(T):
    n, c, r, u = map(int, input().split())

    L = []

    prefix = ['']*n

    listaPiastrelle(n, 0, prefix)

    P_r = []
    P_u = []

    for _ in range(r):
        P_r.append(input().strip())
    
    for _ in range(u):
        P_u.append(int(input()))

    #----------------------

    if(c == 1):
        cont = 0
        for el in L:
            cont = cont +1
        print(cont%COSTANTE)
    
    if(r > 0):
        
        for el in P_r:
            pos = 0
            for e in L:
                if(el == e):

                    print(pos)
                pos = pos + 1


    if(u > 0):
        for el in P_u:
            print(L[el])



