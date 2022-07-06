"""
* user:  VR458382_id202rhp
* fname: ALBERTO
* lname: BARONI
* task:  block_diag_mat
* score: 31.0
* date:  2022-02-02 13:04:30.998880
"""


import numpy as np


def poss_blocks(mat,m,n):
    massimo = 1
    interni = 0
    found = False
    for i in range(m-1):
        if  (not mat[0:i+1,i+1:n].any()  and not mat[i+1:m,0:i+1].any()  ):
            n_mat = mat[i+1:m,i+1:n]
            #print(n_mat)
            interni = 1+poss_blocks(n_mat,m-i-1,n-i-1)
            found = True

        massimo = max(interni,massimo)
        if found: break 
    return massimo



#t2

def poss_blocks_t2(mat,m,n):
    massimo = 1
    interni = 0
    found = False
    for i in range(m-1):
        if  (not mat[0:i+1,i+1:n].any()  and not mat[i+1:m,0:i+1].any()  ):
            n_mat = mat[i+1:m,i+1:n]
            #print(n_mat)
            interni = max(1+poss_blocks(n_mat,m-i-1,n-i-1),massimo)
         
        #estensione a destra
        if i <= n-2: 
            if  (not mat[0:i+1,i+2:n].any()  and not mat[i+1:m,0:i+2].any()  ):
                n_mat = mat[i+1:m,i+2:n]
                #print(n_mat)
                interni =  max(1+poss_blocks(n_mat,m-i-1,n-i-2),massimo)

        #estensione giu
        if i <= m-2:
            if  (not mat[0:i+2,i+1:n].any()  and not mat[i+2:m,0:i+1].any()  ):
                n_mat = mat[i+2:m,i+1:n]
                #print(n_mat)
                interni =  max(1+poss_blocks(n_mat,m-i-2,n-i-1),massimo)



        massimo = max(interni,massimo)
    return massimo

#####main###

t,m,n = map(int,input().strip().split())
mat_p = [ [0]*n ]*m

for i in range(m):
    arr = list(map(int,input().strip().split()))
    mat_p[i] = arr


mat = np.array(mat_p)
if t == 1:
    print(poss_blocks(mat,m,n))
elif t == 2:
    v = poss_blocks_t2((mat,m,n)) -1
    print(v)
    