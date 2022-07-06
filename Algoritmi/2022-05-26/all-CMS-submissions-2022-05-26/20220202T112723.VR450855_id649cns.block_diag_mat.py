"""
* user:  VR450855_id649cns
* fname: CARLO
* lname: VERONESI
* task:  block_diag_mat
* score: 31.0
* date:  2022-02-02 11:27:23.685276
"""
#!/usr/bin/python3
from sys import argv, stderr, stdout, setrecursionlimit
setrecursionlimit(10**6) 

def print_matrice(matrice, n, m):
    for i in range(n):
        for j in range(m):
            print(f"{matrice[i][j]} ", end='')
        print("")

def get_col(matrice, col_idx, n, m):
    col = []
    for i in range(n):
        col.append(matrice[i][col_idx])
    return col

def matr_quadrata(matrice, n, m):
    blocks = 0 # counts
    index = [-1]

    # coeff i, i
    for i in range(n):
        if(i < max(index)):
            continue

        # prendo riga e colonna dell'elemento
        row = matrice[i]
        col = get_col(matrice, i, n, m)

        #print(f"i= {i}")
        #print(row)

        #print(col)
        
        # controllo elementi cercando i non 0
        # righe
        count = 0
        for elem in row:

            if(count > i and elem != 0):
                index.append(count)
            count += 1
        #print(index)
        
        # colonne
        count = 0
        for elem in col:
            if(count > i and elem != 0):
                index.append(count)
            count += 1
        #print(index)

        if(max(index)  <= i):
            blocks += 1

    return blocks


# header
t, n, m = map(int,input().strip().split())

# matrice
matrice = []
for i in range(n):
    row = input().strip().split()
    # converting
    row = [ int(x) for x in row]
    matrice.append(row)
'''
# MIO
t = 1
matrice = [[1, 0, 0], [0, 2, 0], [0, 0, 3]]
#matrice = [[1,0,0,0],[0,2,3,0],[0,4,5,0],[0,0,0,0]]
matrice = [[1,0,0,0],[0,0,2,0],[0,0,0,3],[0,0,0,0]]
matrice=[[1,0,0,0],[4,1,0,0],[0,0,1,3],[0,0,0,0]]
n = len(matrice)
m = len(matrice[0])

#print_matrice(matrice, n, m)
'''


if(t == 1): # matr quadrata
    count = matr_quadrata(matrice, n, m)
    print(count)
else:# altri task
    print("TODO")
