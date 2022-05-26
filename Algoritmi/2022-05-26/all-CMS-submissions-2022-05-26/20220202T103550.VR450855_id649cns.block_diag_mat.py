"""
* user:  VR450855_id649cns
* fname: CARLO
* lname: VERONESI
* task:  block_diag_mat
* score: 0.0
* date:  2022-02-02 10:35:50.895147
"""
#!/usr/bin/python3
from sys import argv, stderr, stdout, setrecursionlimit
setrecursionlimit(10**6) 

def print_matrice(matrice, n, m):
    for i in range(n):
        for j in range(m):
            print(f"{matrice[i][j]} ", end='')
        print("")

def non_diag_vuoto(matrix, n, m):
    for i in range(n):
        for j in range(m):
            if i == j:
                continue
            elif matrix[i][j] != 0:
                return False
    return True


'''
# t=1
def max_quadr(matrix, n, m):
    if(n == 1):
        return 1

    if(non_diag_vuoto(matrix, n, m)): # matrice diagonale
        return max_quadr(matrix, n-1, m-1) + max_quadr(matrix,
    else:
        return None
'''

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
n = 3
m = 3
matrice = [[1, 0, 0], [0, 2, 0], [0, 0, 3]]

#
'''
#print_matrice(matrice, n, m)


if(t == 1): # matr quadrata
    #ret = max_quadr(matrice)
    if(non_diag_vuoto(matrice, n, m)):
        print(n)
    else:
        print(-1)
    #print(ret)
    pass
else:
    exit()
