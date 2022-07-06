"""
* user:  VR456970_id236bst
* fname: JACOPO
* lname: PIZZOLI
* task:  block_diag_mat
* score: 0.0
* date:  2022-02-02 12:37:37.580667
"""
#!/usr/bin/env python3
import sys
sys.setrecursionlimit(10**9)
import numpy as np 

t, m, n = map(int,input().strip().split())
#print(f"t={t}, m={m}, n={n}")
q = [[0]* m for x in range(n)]
for i in range(m):
    q[i] = list(map(int,input().strip().split())) 
#print(f"matrice = {q}")

def quad_block (q,m,n):
    if len(q) < 3:
        return 1 
    else: # almeno 3*3
        a = 0
        determ = np.linalg.det(q)
        #print(f"determinante = {determ}") 
        if determ == 0:
            a = 2
            return a  
        
        c, c_up, c_down = 0,0,0
        for i in range(1,m):
            c += q[0][i]
        for j in range(1,n):
            c += q[i][0]
        if c==0:
            a = a + 1

        diagon = np.diag(q)
        for i in range (1,len(diagon)):
            if (diagon[i] != 0):
                c = c+1
        a = a + 1
        diagon_up = np.diag(q,1)
        for i in range (len(diagon_up)):
            if (diagon_up[i] != 0):
                c_up = c_up+1
        diagon_down = np.diag(q,-1)
        for i in range (len(diagon_down)):
            if (diagon_down[i] != 0):
                c_down = c_down+1
        if (c_up > c or c_down > c):
            a = a + 1        
    return a        

def non_quad_block(q,m,n):
    if len(q) < 2:
        return 1 
    else:  
        c, c_up, c_down = 0,0,0
        diagon = np.diag(q)
        for i in range (len(diagon)):
            if (diagon[i] != 0):
                c = c+1
        diagon_up = np.diag(q,1)
        for i in range (len(diagon_up)):
            if (diagon_up[i] != 0):
                c_up = c_up+1
        diagon_down = np.diag(q,-1)
        for i in range (len(diagon_down)):
            if (diagon_down[i] != 0):
                c_down = c_down+1
        if (c_up > c or c_down > c):
            c = c+1      
    return c 

def generic_block(q,m,n):
    return 0

if t == 1:
    print(quad_block(q,m,n))
elif t == 2:
    print(non_quad_block(q,m,n))
elif t == 3:
    print(generic_block(q,m,n))
