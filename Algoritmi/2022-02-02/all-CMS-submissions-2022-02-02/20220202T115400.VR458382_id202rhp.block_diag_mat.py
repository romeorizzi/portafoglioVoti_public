"""
* user:  VR458382_id202rhp
* fname: ALBERTO
* lname: BARONI
* task:  block_diag_mat
* score: 0.0
* date:  2022-02-02 11:54:00.625214
"""


import numpy as np


def poss_blocks(mat,m,n):
    massimo = 1
    interni = 0
    for i in range(m-1):
        if  (not mat[0:i+1,i+1:n].any()  and not mat[i+1:m,0:i+1].any()  ):
            n_mat = mat[i+1:m,i+1:n]
            #print(n_mat)
            interni = 1+poss_blocks(n_mat,m-i-1,n-i-1)
        massimo = max(interni,massimo)
    return massimo


#####main###

t,m,n = map(int,input().strip().split())
mat_p = [ [0]*n ]*m

for i in range(m):
    arr = list(map(int,input().strip().split()))
    for j in range(n):
        mat_p[i][j] = arr[j]


mat = np.array(mat_p)
if t == 1:
    print(poss_blocks(mat,m,n))